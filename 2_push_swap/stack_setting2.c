/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:11:15 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/10 03:09:57 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find Array for Indexing
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

// Indexing stack for Sandglass
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

// Parameter Overlap Check
void	overlap_check(t_deq *stack, int *array, int size)
{
	int	idx;

	idx = 1;
	while (idx < size)
	{
		if (array[idx] == array[idx - 1])
		{
			ft_printf("Error\n");
			free_stack(stack);
			free(array);
			exit(0);
		}
		idx++;
	}
}

// Quick Sort for Indexing
void	sorting_array(int *array, int s, int e)
{
	int	pivot;
	int	tmp;
	int	l;
	int	r;

	pivot = (s + e) / 2;
	l = s;
	r = e;
	while (l < r)
	{
		while (array[l] < array[pivot] && l < pivot)
			l++;
		while (array[r] > array[pivot] && r > pivot)
			r--;
		tmp = array[l];
		array[l++] = array[r];
		array[r--] = tmp;
	}
	if (pivot > s)
		sorting_array(array, s, pivot);
	if (e > pivot + 1)
		sorting_array(array, pivot + 1, e);
}

// Stack to Array for Indexing
void	stack_to_array(t_deq *stack)
{
	t_node	*now;
	int		*array;
	int		idx;

	array = (int *)malloc(sizeof(int) * (stack->size));
	if (!array)
	{
		free_stack(stack);
		exit(0);
	}
	idx = 0;
	now = stack->top;
	while (now != NULL)
	{
		array[idx++] = now->data;
		now = now->next;
	}
	sorting_array(array, 0, stack->size - 1);
	overlap_check(stack, array, stack->size);
	indexing_stack(stack, array);
	free(array);
}
