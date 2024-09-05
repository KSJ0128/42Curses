/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:58:23 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/31 21:38:26 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_arg *arg)
{
	int	idx;

	arg->fork = (int *)malloc(sizeof(int) * arg->philo_num);
	if (!(arg->fork))
		return (free_fork(arg));
	arg->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (arg->philo_num));
	if (!(arg->fork_mutex))
		return (free_fork(arg));
	idx = 0;
	while (idx < arg->philo_num)
	{
		if(pthread_mutex_init(&(arg->fork_mutex[idx]), NULL))
			return (free_mutex(arg, idx));
		idx++;
	}
	return (1);
}

int	init_arg(t_arg **arg, int argc, char ** argv)
{
	(*arg) = (t_arg *)malloc(sizeof(t_arg));
	if (!(*arg))
		return (FAIL);
	(*arg)->philo_num = ft_atoi(argv[1]);
	(*arg)->time_to_die = ft_atoi(argv[2]);
	(*arg)->time_to_eat = ft_atoi(argv[3]);
	(*arg)->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*arg)->must_eat = ft_atoi(argv[5]);
	(*arg)->dead_plag = LIVE;
	if (gettimeofday(&((*arg)->start_time), NULL))
		return (free_fork(*arg));
	if (!init_fork((*arg)))
		return (FAIL);
	if (pthread_mutex_init(&((*arg)->dead_mutex), NULL))
		return (free_mutex(*arg, (*arg)->philo_num));
	if (pthread_mutex_init(&((*arg)->print_mutex), NULL))
		return (free_mutex(*arg, (*arg)->philo_num));
	return (SUCCESS);
}

int	init_philo(t_philo **philo, t_arg *arg)
{
	int	idx;

	(*philo) = (t_philo *)malloc(sizeof(t_philo) * arg->philo_num);
	if (!(*philo))
		return (free_arg(arg));
	idx = 0;
	while (idx < arg->philo_num)
	{
		(*philo)[idx].arg = arg;
		(*philo)[idx].id = idx + 1;
		(*philo)[idx].eat_cnt = 0;
		(*philo)[idx].left = (*philo)[idx].id % (*philo)->arg->philo_num;
		(*philo)[idx].right = (*philo)[idx].id - 1;
		(*philo)[idx].dead = LIVE;
		update_die_time(*philo);
		idx++;
	}
	return (SUCCESS);
}
