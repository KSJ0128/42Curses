/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:15:56 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/26 20:31:14 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_deq *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->next;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->bottom = stack->top;
	stack->top = tmp;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
}

void	rotate_all(t_deq *p, t_deq *q)
{
	rotate(p);
	rotate(q);
}

void	r_rotate(t_deq *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->bottom->prev;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	stack->bottom = tmp;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
}

void	r_rotate_all(t_deq *p, t_deq *q)
{
	r_rotate(p);
	r_rotate(q);
}

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
		handle_exception(1);
	while (*str >= '0' && *str <= '9')
	{
		if (*str < '0' || *str > '9')
			handle_exception(1);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
