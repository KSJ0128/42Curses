/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:42:48 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/31 22:07:51 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(t_arg *arg, int argc)
{
	if (arg->time_to_die < 0 || arg->time_to_eat < 0 \
	|| arg->time_to_sleep < 0 || (argc == 6 && arg->must_eat < 0))
	{
		free_arg(arg);
		return (handle_error(0));
	}
	else if (arg->philo_num == 1)
	{
		free_arg(arg);
		return (handle_error(1));
	}
	return (SUCCESS);
}

int main(int argc, char ** argv)
{
	t_arg	*arg;
	t_philo	*philo;

	if (argc != 5 && argc != 6) // 인자의 개수가 올바르지 않은 경우
		return (handle_error(0));
	if (ft_atoi(argv[1]) == -1 || ft_atoi(argv[1]) == 1) // 철학자 수가 올바르지 않은 경우
		return (handle_error(1));
	if (!init_arg(&arg, argc, argv)) // malloc error
		return (handle_error(2));
	if (!check_arg(arg, argc)) // 인자가 올바르지 않게 들어온 경우
		return (0);
	if (!init_philo(&philo, arg)) // malloc error
		return (handle_error(2));
	simulation(philo);
	return (0);
}

/*
테스트
./philo 5 610 200 200  : 무한루프
./philo 5 410 200 200  : 죽음
./philo 4 410 200 200  : 무한루프
./philo 200 410 200 200  : 무한루프
./philo 199 610 200 200  : 무한루프

평가표
./philo 1 800 200 200, the philosopher should not eat and should die!
./philo 5 800 200 200, no one should die!
./philo 5 800 200 200 7, no one should die and the simulation should stop when all the philosopher has eaten at least 7 times each.
./philo 4 410 200 200, no one should die!
./philo 4 310 200 100, a philosopher should die!
*/
