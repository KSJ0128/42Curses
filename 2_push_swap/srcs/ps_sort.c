/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:47:04 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/15 15:46:38 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_deq *stack_a)
{
	t_node	*node;
	int		roll;

	roll = 0;
	node = stack_a->top;
	while (node->data != 0)
	{
		node = node->next;
		roll++;
	}
	if (roll > (stack_a->size / 2))
	{
		roll = stack_a->size - roll;
		while (stack_a->top->data != 0)
		{
			r_rotate(stack_a);
			ft_printf("rra\n");
		}
		return ;
	}
	while (stack_a->top->data != 0)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

void	sorting_two(t_deq *stack_a)
{
	if (stack_a->top->data > stack_a->bottom->data)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
}

void	sorting_three_one(t_deq *stack_a)
{
	t_node	*one;
	t_node	*two;
	t_node	*thr;

	one = stack_a->top;
	two = one->next;
	thr = stack_a->bottom;
	if (one->data < thr->data && thr->data < two->data)
	{
		r_rotate(stack_a);
		swap(stack_a);
		ft_printf("rra\nsa\n");
	}
	else if (two->data < one->data && one->data < thr->data)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if (thr->data < one->data && one->data < two->data)
	{
		r_rotate(stack_a);
		ft_printf("rra\n");
	}
	else
		sorting_three_two(stack_a);
}

void	sorting_three_two(t_deq *stack_a)
{
	t_node	*one;
	t_node	*two;
	t_node	*thr;

	one = stack_a->top;
	two = one->next;
	thr = stack_a->bottom;
	if (two->data < thr->data && thr->data < one->data)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else if (thr->data < two->data && two->data < one->data)
	{
		swap(stack_a);
		r_rotate(stack_a);
		ft_printf("sa\nrra\n");
	}
}

void	sorting_a(t_deq *stack_a)
{
	t_node	*one;
	t_node	*two;
	t_node	*thr;

	one = stack_a->top;
	two = one->next;
	thr = stack_a->bottom;
	if (thr->data > one->data && thr->data < two->data)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if (one->data > two->data && one->data < thr->data)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if (two->data > thr->data && one->data > two->data)
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
}
