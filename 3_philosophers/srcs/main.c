/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:42:48 by seojkim           #+#    #+#             */
/*   Updated: 2025/01/14 23:56:39 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;

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
