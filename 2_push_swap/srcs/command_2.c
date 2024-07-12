/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:15:56 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/13 01:18:40 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_deq *stack) {
    t_node *node;

    if (stack->size < 2)
        return;
	node = pop_top(stack);
	push_bottom(stack, node);
}


void	rotate_all(t_deq *p, t_deq *q)
{
	rotate(p);
	rotate(q);
}

void	r_rotate(t_deq *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = pop_bottom(stack);
	push_top(stack, node);
}

void	r_rotate_all(t_deq *p, t_deq *q)
{
	r_rotate(p);
	r_rotate(q);
}
