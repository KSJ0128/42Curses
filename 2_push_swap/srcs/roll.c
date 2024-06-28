/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:17:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/28 13:26:38 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_a_b(t_deq *stack_a, t_deq *stack_b, int roll_b, int roll_a)
{
	roll_a = stack_a->size - roll_a;
	roll_b = stack_b->size - roll_b;
	while (roll_a > 0 && roll_b > 0)
	{
		r_rotate_all(stack_a, stack_b);
		ft_printf("rrr\n");
	}
	while (roll_a > 0)
	{
		r_rotate(stack_a);
		ft_printf("rra\n");
	}
	while (roll_b > 0)
	{
		r_rotate(stack_b);
		ft_printf("rrb\n");
	}
}

void	optimize_a(t_deq *stack_a, int roll_a)
{
	roll_a = stack_a->size - roll_a;
	while (roll_a > 0)
	{
		r_rotate(stack_a);
		ft_printf("rra\n");
	}
}

void	optimize_b(t_deq *stack_b, int roll_b)
{
	roll_b = stack_b->size - roll_b;
	while (roll_b > 0)
	{
		r_rotate(stack_b);
		ft_printf("rrb\n");
	}
}

void	roll_a_b(t_deq *stack_a, t_deq *stack_b, int roll_b, int roll_a)
{
	while (roll_a > 0 && roll_b > 0)
	{
		rotate_all(stack_a, stack_b);
		ft_printf("rr\n");
	}
	while (roll_a > 0)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	while (roll_b > 0)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
}
