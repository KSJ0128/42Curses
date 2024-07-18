/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setting2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:11:15 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/17 13:07:16 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_data(t_deq *stack, int *array, int idx)
{
	t_node	*now;

	now = stack->top;
	while (now != NULL)
	{
		if (array[idx] == now->data)
			break ;
		now = now->next;
	}
	return (now);
}

void	indexing_stack(t_deq *stack, int *array)
{
	int		idx;
	t_node	*node;

	idx = 0;
	while (idx < stack->size)
	{
		node = find_data(stack, array, idx);
		node->data = idx;
		idx++;
	}
}

void	overlap_check(int *array, int size)
{
	int	idx;

	idx = 1;
	while (idx < size)
	{
		if (array[idx] == array[idx - 1])
			handle_exception(0);
		idx++;
	}
}

void	sorting_array(int *array, int s, int e)
{
	int	pivot;
	int	tmp;
	int	l;
	int	r;

	pivot = array[(s + e) / 2];
	l = s;
	r = e;
	while (l <= r)
	{
		while (array[l] < pivot)
			l++;
		while (array[r] > pivot)
			r--;
		if (l <= r)
		{
			tmp = array[l];
			array[l++] = array[r];
			array[r--] = tmp;
		}
	}
	if (s < r)
		sorting_array(array, s, r);
	if (l < e)
		sorting_array(array, l, e);
}

// Stack to Array for Indexing
void	stack_to_array(t_deq *stack)
{
	t_node	*now;
	int		*array;
	int		idx;

	array = (int *)malloc(sizeof(int) * (stack->size));
	if (!array)
		exit(1);
	idx = 0;
	now = stack->top;
	while (now != NULL)
	{
		array[idx++] = now->data;
		now = now->next;
	}
	sorting_array(array, 0, stack->size - 1);
	overlap_check(array, stack->size);
	indexing_stack(stack, array);
	free(array);
}
