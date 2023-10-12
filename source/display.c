/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:40:22 by afont             #+#    #+#             */
/*   Updated: 2023/10/11 22:40:27 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philosopher.h"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define DEFAULT "\033[39m"
#define RESET "\033[0m"

int	ft_intlen(unsigned long long n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*init_color(int i)
{
	char	*color[7];

	color[0] = RED;
	color[1] = GREEN;
	color[2] = YELLOW;
	color[3] = BLUE;
	color[4] = MAGENTA;
	color[5] = CYAN;
	color[6] = DEFAULT;
	return (color[i % 7]);
}

void	ft_display(t_philo *philo, char *str)
{
	int			i;
	static int	flag;
	char		*color;

	color = init_color(philo->id);
	i = -1;
	if (flag++ == 0)
		printf("┏━━━━━━━━━┳━━━━━━┳━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃ ");
	while ((++i + ft_intlen(ft_gettime() - philo->data->start_time)) < 7)
		printf(" ");
	printf("%llu ┃ ", ft_gettime() - philo->data->start_time);
	i = -1;
	while ((++i + ft_intlen(philo->id)) < 4)
		printf(" ");
	printf("%s%d%s ┃ ", color, philo->id, RESET);
	i = -1;
	while ((++i + ft_strlen(str)) < 18)
		printf(" ");
	printf("%s%s%s ┃\n", color, str, RESET);
}
