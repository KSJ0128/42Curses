/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:29:26 by seojkim           #+#    #+#             */
/*   Updated: 2025/01/14 23:58:07 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_t *first_fork;
	pthread_mutex_t *second_fork;

	if (check_stop_flag(data))
		return (0);
	if (philo->id % 2 == 0)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	pthread_mutex_lock(first_fork);
	print_philo(philo, philo->id, "has taken a fork");
	if (check_stop_flag(data))
	{
		pthread_mutex_unlock(first_fork);
		return (0);
	}
	pthread_mutex_lock(second_fork);
	print_philo(philo, philo->id, "has taken a fork");
	return (1);
}

int	eating(t_philo *philo, t_data *data)
{
	int	result;

	result = 1;
	if (check_stop_flag(data))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	print_philo(philo, philo->id, "is eating");
	pthread_mutex_lock(&data->meal_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&data->meal_mutex);
	ft_usleep(data->eat_time, data);
	pthread_mutex_lock(&data->meal_mutex);
	philo->eat_cnt++;
	if (data->eat_num != -1 && philo->eat_cnt >= data->eat_num && check_stop_flag(data))
		result = 0;
	pthread_mutex_unlock(&data->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (check_stop_flag(data))
		return (0);
	return (result);
}

int	sleeping(t_philo *philo, t_data *data)
{
	if (check_stop_flag(data))
		return (0);
	print_philo(philo, philo->id, "is sleeping");
	ft_usleep(data->sleep_time, data);
	return (1);
}

int	thinking(t_philo *philo, t_data *data)
{
	if (check_stop_flag(data))
		return (0);
	print_philo(philo, philo->id, "is thinking");
	return (1);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (get_time() < philo->start)
		usleep(100);
	if (philo->id % 2 == 0)
		ft_usleep(data->eat_time / 2, data);
	while (1)
	{
		if (get_fork(philo, data) == 0)
			break ;
		if (eating(philo, data) == 0)
			break ;
		if (sleeping(philo, data) == 0)
			break ;
		if (thinking(philo, data) == 0)
			break ;
	}
	return (NULL);
}

void	run_philo(t_data *data, t_philo *philos, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_create(&threads[i], NULL, philo_routine, &philos[i]);
		i++;
	}
	monitoring(philos, data);
	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
