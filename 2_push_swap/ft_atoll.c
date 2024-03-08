/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:02:42 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/06 22:00:41 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_strlen(const char *s)
{
	unsigned int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	int i;

	i = 0;
	while (size > 1 && src[i] != '\0')
	{
		*(dest + i) = *(src + i);
		size--;
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

long long ft_atoll(const char *str)
{
	long long num;
	long long sign;

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
		return (NONE_INTEGER);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
