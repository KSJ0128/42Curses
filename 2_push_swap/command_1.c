/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:48:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/04 19:53:21 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(p_deq *stack)
{
	p_node *first;
	p_node *second;
	p_node *third;

	first = stack->top;
	second = first->next;
	third = second->next;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	third->prev = second;
	stack->top = second;
}

void swap_all(p_deq *p, p_deq *q)
{
	swap(p);
	swap(q);
}

void push(p_deq *p, p_deq *q)
{
	p_node *p_top;
	p_node *q_top;

	if (q->size == 0)
		return ;
	p_top = p->top;
	q_top = q->top;
	q_top->next->prev = NULL;
	q->top = q_top->next;
	if (p->size == 0)
	{
		p->top = q_top;
		q_top->next = NULL;
		q_top->prev = NULL;
	}
	else
	{
		q_top->next = p_top;
		p_top->prev = q_top;
		p->top = q_top;
	}
	p->size++;
	q->size--;
}