/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:41:56 by afont             #+#    #+#             */
/*   Updated: 2023/10/11 22:41:58 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

unsigned long long	ft_atoi(const char *str)
{
	unsigned long long	num;

	num = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return (num);
}

unsigned long long	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(unsigned long long time)
{
	unsigned long long	start;

	start = ft_gettime();
	while ((ft_gettime() - start) < time)
		usleep(time / 10);
}

int	all_full(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		if (data->philos[i].eat_count < data->eat_num)
			return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
