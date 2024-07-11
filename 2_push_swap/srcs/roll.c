/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:17:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/12 00:41:09 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_a_b(t_deq *stack_a, t_deq *stack_b, int roll_a, int roll_b)
{
	roll_a = stack_a->size - roll_a;
	roll_b = stack_b->size - roll_b;
	while (roll_a > 0 && roll_b > 0)
	{
		r_rotate_all(stack_a, stack_b);
		roll_a--;
		roll_b--;
		ft_printf("rrr\n");
	}
	while (roll_a > 0)
	{
		r_rotate(stack_a);
		ft_printf("rra\n");
		roll_a--;
	}
	while (roll_b > 0)
	{
		r_rotate(stack_b);
		ft_printf("rrb\n");
		roll_b--;
	}
}

void	optimize_a(t_deq *stack_a, t_deq *stack_b, int roll_a, int roll_b)
{
	roll_a = stack_a->size - roll_a;
	while (roll_a > 0)
	{
		r_rotate(stack_a);
		ft_printf("rra\n");
		roll_a--;
	}
	while (roll_b > 0)
	{
		rotate(stack_b);
		ft_printf("rb\n");
		roll_b--;
	}
}

void	optimize_b(t_deq *stack_a, t_deq *stack_b, int roll_a, int roll_b)
{
	roll_b = stack_b->size - roll_b;
	while (roll_b > 0)
	{
		r_rotate(stack_b);
		ft_printf("rrb\n");
		roll_b--;
	}
	while (roll_a > 0)
	{
		rotate(stack_a);
		ft_printf("ra\n");
		roll_a--;
	}
}

void	roll_a_b(t_deq *stack_a, t_deq *stack_b, int roll_a, int roll_b)
{
	while (roll_a > 0 && roll_b > 0)
	{
		rotate_all(stack_a, stack_b);
		ft_printf("rr\n");
		roll_b--;
		roll_a--;
	}
	while (roll_a > 0)
	{
		rotate(stack_a);
		ft_printf("ra\n");
		roll_a--;
	}
	while (roll_b > 0)
	{
		rotate(stack_b);
		ft_printf("rb\n");
		roll_b--;
	}
}
