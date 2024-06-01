/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandglass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:33:41 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/20 22:00:13 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a_to_b(t_deq *stack_a, t_deq *stack_b)
{
	int		idx;
	double	range;

	idx = 0;
	range = stack_a->size * 0.000000053 + 0.03 * stack_a->size + 14.5;
	while (stack_a->size > 0)
	{
		if (stack_a->top->data < idx + range)
		{
			idx++;
			push(stack_a, stack_b);
			if (stack_b->top->data > idx - 1)
				rotate(stack_b);
		}
		else
			rotate(stack_a);
	}
}

void push_b_to_a(t_deq *stack_b, t_deq *stack_a)
{
	t_node	*a_node;
	t_node	*b_node;

	while (stack_b->size > 0)
	{
		if (stack_b->top->data > stack_b->bottom->data)
			push(stack_b, stack_a);
		else
		{
			r_rotate(stack_b);
			push(stack_b, stack_a);
		}
	}
}

void	sandglass(t_deq *stack_a)
{
	t_deq	*stack_b;

	stack_b = stack_init();
	if (!stack_b)
	{
		free_stack(stack_a);
		exit (0);
	}
	push_a_to_b(stack_a, stack_b);
	ft_printf("스택 B\n");
	print_stack(stack_b);
	push_b_to_a(stack_b, stack_a);
}
