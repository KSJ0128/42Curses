/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:33:41 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/28 13:34:37 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_deq *stack_a)
{
	while (stack_a->top->data != 0)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

void	do_cmd(t_deq *stack_a, t_deq *stack_b, int roll_b, int roll_a)
{
	if (roll_a > (stack_a->size / 2) && roll_b > (stack_b->size / 2))
		optimize_a_b(stack_a, stack_b, roll_b, roll_a);
	else if (roll_a > (stack_a->size / 2))
		optimize_a(stack_a, roll_a);
	else if (roll_b > (stack_b->size / 2))
		optimize_b(stack_b, roll_b);
	else
		roll_a_b(stack_a, stack_b, roll_b, roll_a);
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

int	counting_cmd(const t_deq *stack_a, int x, int *roll_a)
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
	*roll_a = cmd;
	return (cmd);
}

// stack_b의 특정 원소가 알맞는 위치에 위치하는 명령어의 개수 찾기
int	searching_b(const t_deq *stack_a, const t_deq *stack_b, int roll_b, int *roll_a)
{
	int idx;
	int	cmd_cnt;
	t_node	*node;

	idx = 0;
	node = stack_b->top;
	while (idx < roll_b) // stack_b rotate 해서 특정 원소가 top으로 오게
	{
		node = node->next;
		idx++;
	}
	cmd_cnt = counting_cmd(stack_a, node->data, roll_a) + roll_b;
	return (cmd_cnt);
}

// Complete Sorting A
void	push_b_to_a(t_deq *stack_a, t_deq *stack_b)
{
	int	tmp;
	int	idx;
	int	total_cmd; // 최소 roll_a + roll_b
	int roll_a; // 최소 roll_a
	int	roll_b; // 최소 roll_b

	roll_b = MAX;
	while (stack_b->size > 0)
	{
		idx = 0;
		while (stack_b->size > idx)
		{
			tmp = searching_b(stack_a, stack_b, idx, &roll_a);
			if (total_cmd < tmp)
			{
				total_cmd = tmp;
				roll_b = idx;
			}
			idx++;
		}
		do_cmd(stack_a, stack_b, roll_b, roll_a);
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
}
