/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:42:42 by seojkim           #+#    #+#             */
/*   Updated: 2024/09/02 19:20:13 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = -1;
	}
	if (*str == '\0' || *str < '0' || *str > '9')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0' && (*str < '0' || *str > '9'))
			return (-1);
	return (sign * num);
}

long	ft_get_time(struct timeval start, struct timeval now)
{
	return ((now.tv_sec * 1000 + now.tv_usec / 1000) \
		- (start.tv_sec * 1000 + start.tv_usec / 1000));
}

void	is_dead(t_philo *philo, struct timeval now)
{
	int can_live;

	can_live = philo->arg->time_to_die;
	if (philo->last_meal.tv_sec + can_live / 1000 < now.tv_sec || \
	((philo->last_meal.tv_sec + can_live / 1000 == now.tv_sec) && \
	(philo->last_meal.tv_usec + (can_live % 1000) * 1000 < now.tv_usec)))
	{
		pthread_mutex_lock(&(philo->arg->dead_mutex));
		philo->dead = DEATH;
		print_state(philo, 3, now);
		pthread_mutex_unlock(&(philo->arg->dead_mutex));
	}
	else
	{
		philo->eat_cnt++;
		update_die_time(philo);
		print_state(philo, 0, now);
	}
}

void	update_die_time(t_philo *philo)
{
	int can_live;

	can_live = philo->arg->time_to_die;
	philo->last_meal.tv_sec += philo->arg->start_time.tv_sec + can_live / 1000;
	philo->last_meal.tv_usec += philo->arg->start_time.tv_usec + \
		(can_live % 1000) * 1000;
	if (philo->last_meal.tv_usec >= 1000000)
	{
		philo->last_meal.tv_sec += 1;
		philo->last_meal.tv_usec -= 1000000;
	}
}

void	print_state(t_philo *philo, int state, struct timeval now)
{
	pthread_mutex_lock(&(philo->arg->print_mutex));
	if (state == 0)
	{
		printf("%ld %d has taken a fork\n%ld %d is eating\n",
		ft_get_time(philo->arg->start_time, now), philo->id,
		ft_get_time(philo->arg->start_time, now), philo->id);
	}
	else if (state == 1)
		printf("%ld %d is sleeping\n", ft_get_time(philo->arg->start_time, now), philo->id);
	else if (state == 2)
		printf("%ld %d is thinking\n", ft_get_time(philo->arg->start_time, now), philo->id);
	else if (state == 3)
		printf("%ld %d is died\n", ft_get_time(philo->arg->start_time, now), philo->id);
	pthread_mutex_unlock(&(philo->arg->print_mutex));
}
