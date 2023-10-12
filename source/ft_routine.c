/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:41:00 by afont             #+#    #+#             */
/*   Updated: 2023/10/11 22:41:03 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	philo_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	ft_monitoring(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	ft_monitoring(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->mutex);
	philo->last_eat = ft_gettime();
	pthread_mutex_unlock(&philo->data->mutex);
	ft_monitoring(philo, "is eating");
	ft_usleep(philo->data->eat_time);
	pthread_mutex_unlock(&philo->l_fork);
	ft_monitoring(philo, "has dropped a fork");
	pthread_mutex_unlock(philo->r_fork);
	ft_monitoring(philo, "has dropped a fork");
}

void	*ft_routine(void *philo_data)
{
	t_philo		*philo;
	static int	flag;

	philo = (t_philo *)philo_data;
	if (philo->data->philo_num == 1)
		return (ft_monitoring(philo, "has taken a fork"));
	if (philo->id % 2 == 1)
		ft_usleep(philo->data->eat_time / 2);
	while (1)
	{
		pthread_mutex_lock(&philo->data->mutex);
		if (philo->data->is_end)
		{
			if (flag++ == 0)
				printf("┗━━━━━━━━━┻━━━━━━┻━━━━━━━━━━━━━━━━━━━━┛\n");
			pthread_mutex_unlock(&philo->data->mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->mutex);
		philo_meal(philo);
		ft_monitoring(philo, "is sleeping");
		ft_usleep(philo->data->sleep_time);
		ft_monitoring(philo, "is thinking");
	}
	return (NULL);
}
