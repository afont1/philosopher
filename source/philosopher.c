/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:41:32 by afont             #+#    #+#             */
/*   Updated: 2023/10/11 22:41:38 by afont            ###   ########.fr       */
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
			pthread_mutex_destroy(&data->philos[i].l_fork);
	}
	if (data->philos)
		free(data->philos);
	free(data);
}

void	ft_error(t_data *data, char *str)
{
	ft_free(data);
	printf("Error (%s)\n", str);
	exit(1);
}

void	check_args(t_data *data, int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		ft_error(data, "Too many or not enough arguments");
	i = 0;
	while (argv[++i])
	{
		if (!argv[i][0])
			ft_error(data, "Missing arguments");
		j = -1;
		if (ft_strlen(argv[i]) > 10 || \
		(ft_strlen(argv[i]) == 10 && argv[i][9] > '7'))
			ft_error(data, "Above max int");
		while (argv[i][++j])
			if (argv[i][j] < 48 || argv[i][j] > 57)
				ft_error(data, "Arguments must be digits");
	}
	if (ft_atoi(argv[1]) == 0)
		ft_error(data, "Must have 1 philosopher minimum");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	check_args(data, argc, argv);
	init_data(data, argc, argv);
	init_philos(data);
	start_philo(data);
	ft_free(data);
}
