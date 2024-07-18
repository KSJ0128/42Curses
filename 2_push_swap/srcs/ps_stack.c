/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:47:15 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/17 12:57:34 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_to_a(t_deq *stack_a, t_deq *stack_b)
{
	int		total;
	int		b_idx;
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		exit(1);
	while (stack_b->size > 0)
	{
		b_idx = 0;
		cmd->total_roll = MAX;
		while (stack_b->size > b_idx)
		{
			total = searching_b(stack_a, stack_b, b_idx);
			if (cmd->total_roll > optimize_cmd(stack_a, stack_b, total, b_idx))
			{
				cmd->total_roll = optimize_cmd(stack_a, stack_b, total, b_idx);
				cmd->roll_b = b_idx;
				cmd->roll_a = total - cmd->roll_b;
			}
			b_idx++;
		}
		do_cmd(stack_a, stack_b, cmd);
	}
	free(cmd);
}

void	push_a_to_b(t_deq *stack_a, t_deq *stack_b, int piv_a, int piv_b)
{
	while (stack_b->size < piv_b)
	{
		if (stack_a->top->data > piv_b)
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
		else if (stack_a->top->data > piv_a)
		{
			push(stack_a, stack_b);
			ft_printf("pb\n");
		}
		else
		{
			push(stack_a, stack_b);
			rotate(stack_b);
			ft_printf("pb\nrb\n");
		}
	}
	while (stack_a->size > 3)
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	sorting_a(stack_a);
}
