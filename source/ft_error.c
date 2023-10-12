/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:40:41 by afont             #+#    #+#             */
/*   Updated: 2023/10/11 22:40:53 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	ft_free(t_data *data)
{
	int	i;

	if (data->philo_num)
		pthread_mutex_destroy(&data->mutex);
	if (data->philos && data->philos[0].r_fork)
	{
		i = -1;
		while (++i < data->philo_num)
		{
			pthread_mutex_destroy(&data->philos[i].l_fork);
			data->philos[i].r_fork = NULL;
		}
	}
	if (data->philos)
		free(data->philos);
}

void	ft_error(t_data *data, char *str)
{
	ft_free(data);
	printf("Error (%s)\n", str);
	exit(1);
}
