/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:47:15 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/13 01:19:02 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// Complete Sorting A
void	push_b_to_a(t_deq *stack_a, t_deq *stack_b)
{
	int	total_tmp;
	int	b_idx;
	t_cmd* cmd;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	if (!cmd)
		exit(1);
	while (stack_b->size > 0)
	{
		b_idx = 0;
		cmd->total_roll = MAX;
		while (stack_b->size > b_idx)
		{
			total_tmp = searching_b(stack_a, stack_b, b_idx); // B의 특정 원소를 A로 옮길 때 필요한 최적화 안된 명령어 개수
			if (cmd->total_roll > optimize_cmd(stack_a, stack_b, total_tmp, b_idx))
			{
				cmd->total_roll = optimize_cmd(stack_a, stack_b, total_tmp, b_idx); // 최적화 된 전체 명령어 개수
				cmd->roll_b = b_idx; // 최적화 안된 Roll b 명령어 개수
				cmd->roll_a = total_tmp - cmd->roll_b; // 최적화 안된 Roll a 명령어 개수
			}
			b_idx++;
		}
		do_cmd(stack_a, stack_b, cmd); // 최소 명령어 수 필요한 것 push
	}
	free_stack(stack_b);
}

void	push_a_to_b(t_deq *stack_a, t_deq *stack_b, int pivot_a, int pivot_b)
{
	while (stack_b->size < pivot_b)
	{
		if (stack_a->top->data > pivot_b)
		{
			rotate(stack_a);
			ft_printf("ra\n");
		}
		else if (stack_a->top->data > pivot_a)
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
