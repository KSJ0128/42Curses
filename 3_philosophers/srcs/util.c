/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:42:42 by seojkim           #+#    #+#             */
/*   Updated: 2025/01/12 02:45:11 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	mytime;
	long			result;

	gettimeofday(&mytime, NULL);
	result = ((size_t)mytime.tv_sec * 1000) + ((size_t)mytime.tv_usec / 1000);
	return (result);
}

void	ft_usleep(long time, t_data *data)
{
	long	startTime;

	startTime = get_time();
	while (get_time() - startTime < time)
	{
		if (check_stop_flag(data))
			break ;
		usleep(200);
	}
}

void	destroy_mutex(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}

void	print_philo(t_philo *philo, int id, char *msg)
{
	long long	now;

	now = get_time();
	pthread_mutex_lock(&(philo->data->dead_mutex));
	if (!philo->data->stop_flag) {
		pthread_mutex_lock(&(philo->data->print_mutex));
		printf("%lld %d %s\n", now - philo->start, id, msg);
		pthread_mutex_unlock(&(philo->data->print_mutex));
	}
	pthread_mutex_unlock(&(philo->data->dead_mutex));
}

int	philo_atoi(const char *str, int *val)
{
	long long	ret;
	int			sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	if ((ret > 9223372036854775807 && sign == -1) || ret > 9223372036854775807)
		return (1);
	*val = sign * ret;
	return (0);
}
