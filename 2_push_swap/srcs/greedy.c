/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:33:41 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/13 01:18:19 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	push(stack_b, stack_a);
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
	free_stack(stack_a);
}
