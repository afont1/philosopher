/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:41:47 by afont             #+#    #+#             */
/*   Updated: 2023/10/11 22:41:50 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	*ft_monitoring(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->is_end)
	{
		pthread_mutex_unlock(&philo->data->mutex);
		return (NULL);
	}
	ft_display(philo, str);
	if (str[3] == 'e')
		philo->eat_count += 1;
	pthread_mutex_unlock(&philo->data->mutex);
	return (NULL);
}

int	is_dead_full(t_data *data, int i)
{
	if (ft_gettime() - data->philos[i].last_eat >= data->die_time)
	{
		pthread_mutex_unlock(&data->mutex);
		ft_monitoring(&data->philos[i], "died");
		pthread_mutex_lock(&data->mutex);
		data->is_end = 1;
		pthread_mutex_unlock(&data->mutex);
		return (1);
	}
	return (0);
}

void	ft_supervise(t_data *data)
{
	int	i;

	while (1)
	{
		i = -1;
		pthread_mutex_lock(&data->mutex);
		while (++i < data->philo_num)
			if (is_dead_full(data, i))
				return ;
		if (all_full(data))
		{
			data->is_end = 1;
			pthread_mutex_unlock(&data->mutex);
			return ;
		}
		pthread_mutex_unlock(&data->mutex);
	}
}

void	start_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_lock(&data->mutex);
		data->start_time = ft_gettime();
		pthread_mutex_unlock(&data->mutex);
		if (pthread_create(&data->philos[i].thread, \
		NULL, ft_routine, (void *)&data->philos[i]))
			ft_error(data, "Thread creation failed");
	}
	ft_supervise(data);
	i = -1;
	while (++i < data->philo_num)
		if (pthread_join(data->philos[i].thread, NULL))
			ft_error(data, "Thread join failed");
}
