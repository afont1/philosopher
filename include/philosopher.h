/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:42:22 by afont             #+#    #+#             */
/*   Updated: 2023/10/11 22:42:25 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h> 
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct	s_data
{
	int					philo_num;
	int					is_end;
	unsigned long long	eat_num;
	unsigned long long	die_time;
	unsigned long long	eat_time;
	unsigned long long	sleep_time;
	unsigned long long	start_time;
	t_philo				*philos;
	pthread_mutex_t		mutex;
};

struct	s_philo
{
	int					id;
	unsigned long long	eat_count;
	unsigned long long	last_eat;
	t_data				*data;
	pthread_t			thread;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		l_fork;
};

void				ft_error(t_data *data, char *str);
void				check_args(t_data *data, int argc, char **argv);
unsigned long long	ft_atoi(const char *str);
void				init_data(t_data *data, int argc, char **argv);
unsigned long long	ft_gettime(void);
void				*ft_monitoring(t_philo *philo, char *str);
int					is_dead(t_data *data, int i);
void				ft_supervise(t_data *data);
void				start_philo(t_data *data);
void				init_philos(t_data *data);
void				*ft_routine(void *philo_data);
void				ft_free(t_data *data);
void				ft_usleep(unsigned long long time);
int					all_full(t_data *data);
int					ft_strlen(char *str);
void				ft_display(t_philo *philo, char *str);
int					ft_intlen(unsigned long long n);

#endif
