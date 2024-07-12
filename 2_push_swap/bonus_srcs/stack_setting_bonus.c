/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:26:38 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/12 15:12:12 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_init(int num)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		exit(1);
	tmp->data = num;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_deq	*stack_init()
{
	t_deq	*stack;

	stack = (t_deq *)malloc(sizeof(t_deq));
	if (!stack)
		exit(1);
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
		exit(1);
	now = stack->top;
	while (now != NULL)
	{
		next = now->next;
		free(now);
		now = next;
	}
	free(stack);
}

void	stack_setting(t_deq *stack, int num)
{
	t_node	*new;

	new = node_init(num);
	if (!new)
		exit(1);
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
	long long	idx;
	long long	stack_size;
	long long	num;

	stack_size = 0;
	split_argv = ps_split(argv_num, ' ', &stack_size);
	if (!split_argv)
		exit(1);
	idx = 0;
	while (idx < stack_size)
	{
		num = ft_atoll(split_argv[idx]);
		if (num > MAX || num < MIN)
			handle_exception(1);
		stack_setting(stack, num);
		idx++;
	}
	return (SUCCESS);
}
