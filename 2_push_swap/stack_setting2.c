/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandglass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:11:15 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/08 15:29:49 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

p_node *find_data(p_deq *stack, int *array, int idx)
{
	p_node *now;

	now = stack->top;
	while (now != NULL)
	{
		if (array[idx] == now->data)
			break;
		now = now->next;
	}
	return (now);
}

void indexing_stack(p_deq *stack, int *array)
{
	int idx;
	p_node *node;

	idx = 0;
	while (idx < stack->size)
	{
		node = find_data(stack, array, idx);
		node->data = idx;
		idx++;
	}
}

void sorting_array(int *array, int s, int e)
{
	int pivot;
	int tmp;
	int l;
	int r;

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
		sorting_array(array, pivot+1, e);
}

void overlap_check(p_deq *stack, int *array, int size)
{
	int idx;

	idx = 1;
	while (idx < size)
	{
		if (array[idx] == array[idx-1])
		{
			ft_printf("Error\n");
			free_stack(stack);
			free(array);
			exit(0);
		}
		idx++;
	}
}

void print_array(int *array, int size)
{
	int i = 0;
	ft_printf("Array\n");
	for(int i = 0; i < size; i++)
		ft_printf("%d ", array[i]);
	ft_printf("\n");
}

void stack_to_array(p_deq *stack)
{
	p_node *now;
	int *array;
	int idx;

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
}
