/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:48:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/15 15:53:45 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_deq *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (stack->size < 2)
		return ;
	node1 = pop_top(stack);
	node2 = pop_top(stack);
	push_top(stack, node1);
	push_top(stack, node2);
}

void	swap_all(t_deq *p, t_deq *q)
{
	swap(p);
	swap(q);
}

void	push(t_deq *throw, t_deq *catch)
{
	if (throw->size == 0)
		return ;
	push_top(catch, pop_top(throw));
}
