/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:43:06 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/13 01:07:49 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_top(t_deq *stack, t_node *node)
{
	if (stack->size != 0)
	{
		node->next = stack->top;
		stack->top->prev = node;
		node->prev = NULL;
		stack->top = node;
	}
	else
	{
		stack->top = node;
		stack->bottom = node;
	}
	stack->size++;
}

void	push_bottom(t_deq *stack, t_node *node)
{
	if (stack->size != 0)
	{
		node->prev = stack->bottom;
		stack->bottom->next = node;
		node->next = NULL;
		stack->bottom = node;
	}
	else
	{
		stack->top = node;
		stack->bottom = node;
	}
	stack->size++;
}

t_node	*pop_top(t_deq *stack)
{
	t_node *node;

	node = stack->top;
	if (stack->size == 0)
		return (NULL);
	else if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = node->next;
		stack->top->prev = NULL;
		node->next = NULL;
	}
	stack->size--;
	return (node);
}

t_node	*pop_bottom(t_deq *stack)
{
	t_node *node;

	node = stack->bottom;
	if (stack->size == 0)
		return (NULL);
	else if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->bottom = node->prev;
		stack->bottom->next = NULL;
		node->prev = NULL;
	}
	stack->size--;
	return (node);
}
