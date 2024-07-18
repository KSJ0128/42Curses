/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:42:43 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/17 13:06:51 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	long long	num;
	long long	sign;

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
		handle_exception(0);
	while (*str >= '0' && *str <= '9')
	{
		if (*str < '0' || *str > '9')
			handle_exception(0);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
