/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:53:39 by seojkim           #+#    #+#             */
/*   Updated: 2025/01/14 23:57:39 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_stop_flag(t_data *data)
{
	int	stop_flag;

	pthread_mutex_lock(&data->dead_mutex);
	stop_flag = data->stop_flag;
	pthread_mutex_unlock(&data->dead_mutex);
	return (stop_flag);
}

int	check_philos_state(t_philo *philos, t_data *data)
{
	int	i;
	int	finished_philo;

	i = 0;
	finished_philo = 0;
	while (i < data->philo_num)
	{
		if (check_philo_death(&philos[i], data))
			return (1);
		if (check_philo_full(&philos[i], data))
			finished_philo++;
		i++;
	}
	pthread_mutex_lock(&data->meal_mutex);
	if (data->eat_num != -1 && finished_philo == data->philo_num)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		pthread_mutex_lock(&data->dead_mutex);
		data->stop_flag = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		printf("All philosophers are full!\n");
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}

int	check_philo_full(t_philo *philo, t_data *data)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&data->meal_mutex);
	if (data->eat_num != -1 && philo->eat_cnt >= data->eat_num)
		result = 1;
	pthread_mutex_unlock(&data->meal_mutex);
	return (result);
}

int	check_philo_death(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->meal_mutex);
	if (get_time() - philo->last_eat > data->life_time)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		print_philo(philo, philo->id, "died");
		pthread_mutex_lock(&data->dead_mutex);
		data->stop_flag = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}

void	monitoring(t_philo *philos, t_data *data)
{
	while (1)
	{
		if (check_stop_flag(data))
			break ;
		if (check_philos_state(philos, data))
			break ;
		usleep(100);
	}
}
