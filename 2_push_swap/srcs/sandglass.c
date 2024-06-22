/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandglass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:33:41 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/22 21:57:17 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a_to_b(t_deq *stack_a, t_deq *stack_b, int pivot_a, int pivot_b)
{
	int		idx;

	idx = 0;
	while (stack_a->size > pivot_a)
	{
		if (stack_a->top->data < pivot_a)
			rotate(stack_a);
		else if (stack_a->top->data <= pivot_b)
		{
			push(stack_a, stack_b);
			rotate(stack_b);
		}
		else
			push(stack_a, stack_b);
	}
	while (stack_a->size > 1)
	{
		push(stack_a, stack_b);
		rotate(stack_b);
	}
}

void push_b_to_a(t_deq *stack_b, t_deq *stack_a)
{
	// t_node	*a_node;
	// t_node	*b_node;

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
	int		pivot_a;
	int		pivot_b;

	pivot_a = stack_a->size / 3;
	pivot_b = pivot_a * 2;
	stack_b = stack_init();
	push_a_to_b(stack_a, stack_b, pivot_a, pivot_b);
	ft_printf("스택 A\n");
	print_stack(stack_a);
	ft_printf("스택 B\n");
	print_stack(stack_b);
	push_b_to_a(stack_b, stack_a);
	print_stack(stack_a);
}
