/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:29:26 by seojkim           #+#    #+#             */
/*   Updated: 2024/09/02 20:03:26 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	print_state(philo, 2, now);
}

void	philo_sleep(t_philo *philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	print_state(philo, 1, now);
	usleep(philo->arg->time_to_sleep * 1000);
}

void	philo_eat(t_philo *philo)
{
	struct timeval	now;

	if (philo->id % 2 == 0)
	{
		usleep(10);
		pthread_mutex_lock(&(philo->arg->fork_mutex[philo->left]));
		pthread_mutex_lock(&(philo->arg->fork_mutex[philo->right]));
	}
	else
	{
		pthread_mutex_lock(&(philo->arg->fork_mutex[philo->right]));
		pthread_mutex_lock(&(philo->arg->fork_mutex[philo->left]));
	}
	gettimeofday(&now, NULL);
	is_dead(philo, now);
	pthread_mutex_unlock(&(philo->arg->fork_mutex[philo->left]));
	pthread_mutex_unlock(&(philo->arg->fork_mutex[philo->right]));
	usleep(philo->arg->time_to_eat * 1000);
}

void	thread_start(t_philo *philo)
{
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	simulation(t_philo *philo)
{
	int	idx;

	idx = 0;
	while (idx < philo->arg->philo_num)
	{
		pthread_create(&philo[idx].thread, NULL, (void *)thread_start, (void *)(philo + idx));
		idx++;
	}
	monitering(philo);
	idx = 0;
	while (idx < philo->arg->philo_num)
	{
		pthread_join(philo[idx].thread, NULL);
		idx++;
	}
}
