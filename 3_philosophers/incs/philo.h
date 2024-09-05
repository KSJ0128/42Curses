/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:08:16 by seojkim           #+#    #+#             */
/*   Updated: 2024/09/02 20:02:19 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

#define SUCCESS 1
#define FAIL 0

#define LIVE 1
#define DEATH 0

typedef struct arg
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	struct timeval start_time;
	int	dead_plag;
	pthread_mutex_t dead_mutex;
	pthread_mutex_t print_mutex;
	int *fork;
	pthread_mutex_t	*fork_mutex;
}	t_arg;

typedef struct philo
{
	int	id;
	int	eat_cnt;
	int	left;
	int	right;
	int dead;
	struct timeval last_meal;
	pthread_t thread;
	t_arg *arg;
}	t_philo;

int		handle_error(int errno);
int		ft_atoi(const char *str);
long	ft_get_time(struct timeval start, struct timeval now);
void	update_die_time(t_philo *philo);
void	is_dead(t_philo *philo, struct timeval now);
void	print_state(t_philo *philo, int state, struct timeval now);
int		free_fork(t_arg *arg);
int		free_mutex(t_arg *arg, int end);
int		free_arg(t_arg *arg);
int		free_philo(t_philo *philo, t_arg *arg, int end);
int		init_fork(t_arg *arg);
int		init_arg(t_arg **arg, int argc, char ** argv);
int		init_philo(t_philo **philo, t_arg *arg);
int		check_arg(t_arg *arg, int argc);
void	thread_start(t_philo *philo);
void	simulation(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	monitering(t_philo *philo);

#endif
