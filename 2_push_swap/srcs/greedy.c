/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:33:41 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/12 01:47:33 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_deq *stack_a)
{
	t_node	*node;
	int roll;

	roll = 0;
	node = stack_a->top;
	while (node->data != 0) // stack_b rotate 해서 특정 원소가 top으로 오게
	{
		node = node->next;
		roll++;
	}
	if (roll > (stack_a->size / 2))
	{
		roll = stack_a->size - roll;
		while (stack_a->top->data != 0)
		{
			r_rotate(stack_a);
			ft_printf("rra\n");
		}
		return ;
	}
	while (stack_a->top->data != 0)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

void	do_cmd(t_deq *stack_a, t_deq *stack_b, t_cmd *cmd)
{
	if (cmd->roll_a > (stack_a->size / 2) && cmd->roll_b > (stack_b->size / 2))
		optimize_a_b(stack_a, stack_b, cmd->roll_a, cmd->roll_b);
	else if (cmd->roll_a > (stack_a->size / 2))
		optimize_a(stack_a, stack_b, cmd->roll_a, cmd->roll_b);
	else if (cmd->roll_b > (stack_b->size / 2))
		optimize_b(stack_a, stack_b, cmd->roll_a, cmd->roll_b);
	else
		roll_a_b(stack_a, stack_b, cmd->roll_a, cmd->roll_b);
	push_p(stack_b, stack_a);
	ft_printf("pa\n");
}


int	counting_cmd_top(const t_deq *stack_a, int x)
{
	int		top;
	int		bottom;

	top = stack_a->top->data;
	bottom = stack_a->bottom->data;
	if (bottom < x && top > x && top > bottom)
		return (SUCCESS);
	if (bottom > x && top > x && bottom > top)
		return (SUCCESS);
	if (bottom < x && top < x && bottom > top)
		return (SUCCESS);
	return (ERROR);
}


int	counting_cmd(const t_deq *stack_a, int x)
{
	t_node	*node;
	int		cmd;

	node = stack_a->top;
	cmd = 0;
	while (1)
	{
		if (node->prev == NULL && counting_cmd_top(stack_a, x) == SUCCESS)
			break ;
		if (node->prev != NULL && node->prev->data < x \
		&& node->data > x && node->data > node->prev->data)
			break ;
		if (node->prev != NULL && node->prev->data > x \
		&& node->data > x && node->prev->data > node->data)
			break ;
		if (node->prev != NULL && node->prev->data < x \
		&& node->data < x && node->prev->data > node->data)
			break ;
		node = node->next;
		cmd++;
	}
	return (cmd);
}

// stack_b의 특정 원소가 알맞는 위치에 위치하는 명령어의 개수 찾기
int	searching_b(t_deq *stack_a, t_deq *stack_b, int roll_b)
{
	int idx;
	t_node	*node;

	idx = 0;
	node = stack_b->top;
	while (idx < roll_b) // stack_b rotate 해서 특정 원소가 top으로 오게
	{
		node = node->next;
		idx++;
	}
	return (counting_cmd(stack_a, node->data) + roll_b); // 최적화 전 스택 a roll 수
}

int calculate_cmd(t_deq *stack_a, t_deq *stack_b, int total, int roll_b)
{
	int opt_a;
	int opt_b;

	opt_a = total - roll_b;
	opt_b = roll_b;

	if (opt_a > (stack_a->size / 2))
		opt_a = stack_a->size - opt_a;
	if (opt_b > (stack_b->size / 2))
		opt_b = stack_b->size - opt_b;
	return (opt_a + opt_b);
}

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
			if (cmd->total_roll > calculate_cmd(stack_a, stack_b, total_tmp, b_idx))
			{
				cmd->total_roll = calculate_cmd(stack_a, stack_b, total_tmp, b_idx); // 최적화 된 전체 명령어 개수
				cmd->roll_b = b_idx; // 최적화 안된 Roll b 명령어 개수
				cmd->roll_a = total_tmp - cmd->roll_b; // 최적화 안된 Roll a 명령어 개수
			}
			b_idx++;
		}
		do_cmd(stack_a, stack_b, cmd); // 최소 명령어 수 필요한 것 push
	}
}

void	greedy(t_deq *stack_a)
{
	t_deq	*stack_b;
	int		pivot_a;
	int		pivot_b;

	pivot_a = stack_a->size / 3;
	pivot_b = pivot_a * 2;
	stack_b = stack_init();
	push_a_to_b(stack_a, stack_b, pivot_a, pivot_b);
	push_b_to_a(stack_a, stack_b);
	final_sort(stack_a);
	// print_stack(stack_a);
	// print_stack(stack_b);
}
