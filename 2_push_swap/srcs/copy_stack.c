/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:20:19 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/25 15:42:42 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deq	*copy_stack(t_deq *stack)
{
	t_node	*now;
	t_deq	*new;
	int idx;
	int num;

	idx = 0;
	now = stack->top;
	new = stack_init();
	if (!new)
		exit(1);
	while (now != NULL)
	{
		num = now->data;
		stack_setting(new, num);
		now = now->next;
	}
	return (new);
}