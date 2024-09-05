/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:14:30 by seojkim           #+#    #+#             */
/*   Updated: 2024/09/03 12:12:15 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitering(t_philo *philo)
{
	int	idx;

	while (1)
	{
		idx = 0;
		while (idx < philo->arg->philo_num)
		{
			pthread_mutex_lock(&(philo->arg->dead_mutex));
			if (((philo + idx)->dead) == DEATH)
			{
				philo->arg->dead_plag = DEATH;
				pthread_mutex_unlock(&(philo->arg->dead_mutex));
				return ;
			}
			pthread_mutex_unlock(&(philo->arg->dead_mutex));
			usleep(10);
			idx++;
		}
	}
}
