/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:15:56 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/04 19:53:06 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(p_deq *stack)
{
	p_node *stack_top;
	p_node *stack_bottom;

	stack_top = stack->top;
	stack_bottom = stack->bottom;
	stack_top->next->prev = NULL;
	stack->top = stack_top->next;
	stack_top->prev = stack_bottom;
	stack_top->next = NULL;
	stack_bottom->next = stack_top;
	stack->bottom = stack_top;
}

void rotate_all(p_deq *p, p_deq *q)
{
	rotate(p);
	rotate(q);
}

void r_rotate(p_deq *stack)
{
	p_node *stack_top;
	p_node *stack_bottom;

	stack_top = stack->top;
	stack_bottom = stack->bottom;
	stack_bottom->prev->next = NULL;
	stack->bottom = stack_bottom->prev;
	stack_bottom->next = stack_top;
	stack_bottom->prev = NULL;
	stack_top->prev = stack_bottom;
	stack->top = stack_bottom;
}

void r_rotate_all(p_deq *p, p_deq *q)
{
	r_rotate(p);
	r_rotate(q);
}