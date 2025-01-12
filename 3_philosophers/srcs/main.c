/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:42:48 by seojkim           #+#    #+#             */
/*   Updated: 2025/01/12 00:25:04 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void   check_leak(void)
{
	system("leaks philo");
}

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;

	atexit(check_leak);
	if (ac < 5 || ac > 6)
		return (1);
	if (init_data(ac, av, &data))
	{
		printf("Error\n");
		return (1);
	}
	threads = malloc(sizeof(pthread_t) * data.philo_num);
	if (threads == NULL)
		return (1);
	if (init_mutex(&data, &forks) || init_philo(&data, &philos, forks))
		return (1);
	run_philo(&data, philos, threads);
	destroy_mutex(&data, forks);
	free(threads);
	free(philos);
	free(forks);
	return (0);
}
