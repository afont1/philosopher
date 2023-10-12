/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:40:06 by afont             #+#    #+#             */
/*   Updated: 2023/10/11 22:40:16 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

void	check_args(t_data *data, int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		ft_error(data, "Too many or not enough arguments");
	i = 0;
	while (argv[++i])
	{
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
