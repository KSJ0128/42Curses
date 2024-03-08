/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:26:38 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/08 15:24:39 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

p_node *node_init(int num)
{
	p_node *tmp;

	tmp = (p_node *)malloc(sizeof(p_node));
	if(!tmp)
		return (NULL);
	tmp->data = num;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

p_deq *stack_init()
{
	p_deq *tmp;

	tmp = (p_deq *)malloc(sizeof(p_deq));
	if(!tmp)
		exit (0);
	tmp->size = 0;
	tmp->top = NULL;
	tmp->bottom = NULL;
	return (tmp);
}

void	free_stack(p_deq *stack)
{
	p_node	*now;
	p_node	*next;

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

void push_node_to_stack(p_deq *stack, int num)
{
	p_node *new;

	new = node_init(num);
	if(!new)
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

int parsing_to_stack(char *argv_str, p_deq *stack)
{
	char **argv_stack;
	int idx;
	int stack_size;
	long long num;

	argv_stack = ft_split(argv_str, ' ', &stack_size);
	idx = 0;
	if (stack_size == 0)
		return (ERROR);
	while (idx < stack_size)
	{
		num = ft_atoll(argv_stack[idx]);
		if (num > 2147483647 || num < -2147483648 || num == NONE_INTEGER)
			return (ERROR);
		else
			push_node_to_stack(stack, num);
		idx++;
	}
	return (TRUE);
}

void print_stack(p_deq *stack)
{
	p_node *tmp;

	tmp = stack->top;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int main(int argc, char *argv[])
{
	p_deq *stack_a;
	p_node *node;
	int check;
	int idx;

	if (argc < 2)
		exit(0);
	stack_a = stack_init();
	idx = 1;
	while (idx < argc)
	{
		if (parsing_to_stack(argv[idx], stack_a) == ERROR)
		{
			free_stack(stack_a);
			ft_printf("Error\n");
			exit(0);
		}
		idx++;
	}
	stack_to_array(stack_a);
	print_stack(stack_a);
	return (0);
}
