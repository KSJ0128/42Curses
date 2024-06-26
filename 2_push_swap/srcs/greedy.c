/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:33:41 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/26 20:55:51 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = stack_a->top;
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
		cnt++;
	}
	return (cnt);
}

// stack_b의 특정 원소가 알맞는 위치에 위치하는 명령어의 개수 찾기
int	searching_b(const t_deq *stack_a, const t_deq *stack_b, int roll)
{
	int idx;
	int	cmd_cnt;
	t_node	*node;

	idx = 0;
	node = stack_b->top;
	while (idx < roll) // stack_b rotate 해서 특정 원소가 top으로 오게
	{
		node = node->next;
		idx++;
	}
	cmd_cnt = counting_cmd(stack_a, node->data) + roll;
	return (cmd_cnt);
}

void	do_cmd(t_deq *stack_a, t_deq *stack_b, int cmd_idx)
{
	int		x;
	int		left;
	int		right;
	int		bottom;

	while (cmd_idx > 0)
	{
		rotate(stack_b);
		ft_printf("rb\n");
		cmd_idx--;
	}
	x = stack_b->top->data;
	while (1)
	{
		left = stack_a->top->data;
		right = stack_a->top->next->data;
		bottom = stack_a->bottom->data;
		if (left > right && left > x && x > bottom) // 사이
		{
			push_p(stack_b, stack_a);
			break;
		}
		else if (left < right && left > x && left > bottom && x > bottom) // 오름차순, x가 가장 작은 값
		{
			push_p(stack_b, stack_a);
			break;
		}
		else if (left < right && left < x && left < bottom && x > bottom) // 오름차순, x가 가장 큰 값
		{
			push_p(stack_b, stack_a);
			break;
		}
		else if (left < right && left > x && left < bottom && x < bottom)
		{
			push_p(stack_b, stack_a);
			break;
		}
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

// Complete Sorting A
void	push_b_to_a(t_deq *stack_a, t_deq *stack_b)
{
	int	tmp;
	int	idx;
	int	cmd_min;
	int	cmd_idx;

	cmd_min = MAX;
	while (stack_b->size > 0)
	{
		idx = 0;
		while (stack_b->size > idx)
		{
			tmp = searching_b(stack_a, stack_b, idx);
			if (tmp < cmd_min)
			{
				cmd_min = tmp; // 명령어 개수
				cmd_idx = idx; // 해당 명령어 개수를 사용하는 데이터
			}
			idx++;
		}
		do_cmd(stack_a, stack_b, cmd_idx);
		ft_printf("stack a\n");
		print_stack(stack_a);
		ft_printf("stack b\n");
		print_stack(stack_b);
	}
}
void	final_sort(t_deq *stack_a)
{
	while (stack_a->top->data != 0)
		rotate(stack_a);
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
	ft_printf("push a to b 후\n스택 A\n");
	print_stack(stack_a);
	ft_printf("스택 B\n");
	print_stack(stack_b);
	ft_printf("---------------------------------------아래부터 b->a\n");
	push_b_to_a(stack_a, stack_b);
	final_sort(stack_a);
}
