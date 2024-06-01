/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:26:38 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/17 23:41:17 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_init(int num)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return (ERROR);
	tmp->data = num;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_deq	*stack_init()
{
	t_deq *stack;
	stack = (t_deq *)malloc(sizeof(t_deq));
	if (!stack)
		return (ERROR);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

void	free_stack(t_deq *stack)
{
	t_node	*now;
	t_node	*next;

	if (!stack)
		exit(0);
	now = stack->top;
	while (now != NULL)
	{
		next = now->next;
		free(now);
		now = next;
	}
	free(stack);
}

void	stack_a_setting(t_deq *stack, int num)
{
	t_node	*new;

	new = node_init(num);
	if (!new)
	{
		free_stack(stack);
		exit(0);
	}
	if (stack->size == 0)
		stack->top = new;
	else if (stack->size == 1)
	{
		stack->top->next = new;
		new->prev = stack->top;
	}
	else
	{
		stack->bottom->next = new;
		new->prev = stack->bottom;
	}
	stack->bottom = new;
	stack->size++;
}

int	parsing_to_stack(char *argv_num, t_deq *stack)
{
	char		**split_argv;
	int			idx;
	int			stack_size;
	long long	num;

	split_argv = ft_split(argv_num, ' ', &stack_size);
	idx = 0;
	if (!stack_size)
		return (ERROR);
	while (idx < stack_size)
	{
		num = ft_atoll(split_argv[idx]);
		if (num > 2147483647 || num < -2147483648 || num == NONE_INTEGER)
			return (ERROR);
		else
			stack_a_setting(stack, num);
		idx++;
	}
	return (SUCCESS);
}
