/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:41:11 by afont             #+#    #+#             */
/*   Updated: 2023/10/11 22:41:15 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	init_data(t_data *data, int argc, char **argv)
{
	if (pthread_mutex_init(&data->mutex, NULL) != 0)
		ft_error(data, "Mutex init failed");
	data->philo_num = (int) ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->eat_num = -1;
	data->is_end = 0;
	if (argc == 6)
		data->eat_num = ft_atoi(argv[5]);
}

void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
		ft_error(data, "Malloc failed");
	while (++i < data->philo_num)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].l_fork, NULL) != 0)
			ft_error(data, "Mutex init failed");
		data->philos[i].last_eat = ft_gettime();
	}
	i = -1;
	while (++i < data->philo_num)
		data->philos[i].r_fork = \
	&data->philos[(i + 1) % data->philo_num].l_fork;
}
