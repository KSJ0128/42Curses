/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:08:16 by seojkim           #+#    #+#             */
/*   Updated: 2024/12/28 02:53:04 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/errno.h>

# define SUCCESS	0
# define FAIL		1

typedef struct s_data
{
	int				philo_num;
	int				life_time;
	int				eat_time;
	int				sleep_time;
	int				eat_num;
	int				stop_flag;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	long			start;
	long			last_eat;
	pthread_t		thread;
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

/* init.c */
int	init_data(int ac, char **av, t_data *data);
int	init_mutex(t_data *data, pthread_mutex_t **forks);
int	init_philo(t_data *data, t_philo **philos, pthread_mutex_t *forks);

/* util.c */
long	get_time(void);
void	ft_usleep(long time, t_data *data);
void	destroy_mutex(t_data *data, pthread_mutex_t *forks);
void	print_philo(t_philo *philo, int id, char *msg);
int	philo_atoi(const char *str, int *val);

/* monitering.c */
int	check_stop_flag(t_data *data);
int	check_philos_state(t_philo *philos, t_data *data);
int	check_philo_full(t_philo *philo, t_data *data);
int	check_philo_death(t_philo *philo, t_data *data);
void	monitoring(t_philo *philos, t_data *data);

/* philo.c */
int	get_fork(t_philo *philo, t_data *data);
int	eating(t_philo *philo, t_data *data);
int	sleeping(t_philo *philo, t_data *data);
int	thinking(t_philo *philo, t_data *data);
void	*philo_routine(void *arg);
void	run_philo(t_data *data, t_philo *philos, pthread_t *threads);


#endif
