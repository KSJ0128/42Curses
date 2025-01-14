/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:58:23 by seojkim           #+#    #+#             */
/*   Updated: 2025/01/14 23:56:49 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(int ac, char **av, t_data *data)
{
	data->stop_flag = 0;
	if (philo_atoi(av[1], &(data->philo_num)) \
		|| philo_atoi(av[2], &(data->life_time)) \
		|| philo_atoi(av[3], &(data->eat_time)) \
		|| philo_atoi(av[4], &(data->sleep_time)))
		return (1);
	if (ac == 6 && philo_atoi(av[5], &(data->eat_num)))
		return (1);
	else if (ac != 6)
		data->eat_num = -1;
	if (data->philo_num == 0 || data->life_time == 0 \
		|| data->eat_time < 0 || data->sleep_time < 0)
		return (1);
	return (0);
}

int	init_mutex(t_data *data, pthread_mutex_t **forks)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->dead_mutex, NULL) == -1 || \
		pthread_mutex_init(&data->print_mutex, NULL) == -1 || \
		pthread_mutex_init(&data->meal_mutex, NULL) == -1)
		return (1);
	*forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (*forks == NULL)
		return (1);
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL) == -1)
			return (1);
		i++;
	}
	return (0);
}

int	init_philo(t_data *data, t_philo **philos, pthread_mutex_t *forks)
{
	int		i;
	long	start_time;

	i = 0;
	start_time = get_time() + data->philo_num;
	*philos = malloc(sizeof(t_philo) * data->philo_num);
	if (*philos == NULL)
		return (1);
	while (i < data->philo_num)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eat_cnt = 0;
		(*philos)[i].start = start_time;
		(*philos)[i].last_eat = start_time;
		(*philos)[i].left_fork = &forks[i];
		(*philos)[i].right_fork = &forks[(i + 1) % data->philo_num];
		(*philos)[i].data = data;
		i++;
	}
	return (0);
}
