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
