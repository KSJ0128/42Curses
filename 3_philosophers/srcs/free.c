/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:27:22 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/31 21:03:59 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_fork(t_arg *arg)
{
	if (arg->fork)
		free(arg->fork);
	free(arg);
	return (0);
}

int	free_mutex(t_arg *arg, int end)
{
	int	idx;

	idx = 0;
	while (idx < end)
	{
		pthread_mutex_destroy(&(arg->fork_mutex[idx]));
		idx++;
	}
	free(arg->fork_mutex);
	return (free_fork(arg));
}

int	free_arg(t_arg *arg)
{
	pthread_mutex_destroy(&(arg->print_mutex));
	return (free_mutex(arg, arg->philo_num));
}

int	free_philo(t_philo *philo, t_arg *arg, int end)
{
	int idx;

	idx = 0;
	while (idx < end)
	{
		pthread_join(philo[idx].thread, NULL);
		idx++;
	}
	free(philo);
	return (free_arg(arg));
}
