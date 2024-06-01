/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:48:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/20 21:57:11 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deq *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	stack->top = tmp->next;
	tmp->next = stack->top->next;
	stack->top->next = tmp;
	tmp->prev = stack->top;
	stack->top->prev = NULL;
}

void	swap_all(t_deq *p, t_deq *q)
{
	swap(p);
	swap(q);
}
void	push_setting(t_node *tmp, t_deq *p)
{
	if (p->size == 0)
	{
		p->top = tmp;
		p->bottom = tmp;
		p->bottom->next = NULL;
	}
	else if (p->size == 1)
	{
		p->top = tmp;
		p->top->next = p->bottom;
		p->bottom->prev = p->top;
	}
	else
	{
		tmp->next = p->top;
		p->top = tmp;

		p->top->prev = tmp;
	}
	p->top->prev = NULL;
}

void	push(t_deq *p, t_deq *q)
{
	t_node	*p_top;

	if (p->size == 0)
		return ;
	p_top = p->top;
	if (p->size == 1)
	{
		p->top = NULL;
		p->bottom = NULL;
	}
	else if (p->size > 1)
	{
		p->top = p_top->next;
		p->top->prev = NULL;
	}
	if (q->size == 0)
	{
		q->top = p_top;
		q->bottom = p_top;
		q->top->next = NULL;
	}
	else if (q->size == 1)
	{
		q->top = p_top;
		q->top->next = q->bottom;
		q->bottom->prev = q->top;
	}
	else
	{
		p_top->next = q->top;
		q->top->prev = p_top;
		q->top = p_top;
	}
	q->top->prev = NULL;
	p->size--;
	q->size++;
}

void	rotate(t_deq *stack)
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

void	rotate_all(t_deq *p, t_deq *q)
{
	rotate(p);
	rotate(q);
}
