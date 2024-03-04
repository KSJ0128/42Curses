/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:26:38 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/04 20:13:45 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, int check)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		check = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		check = 0;
	return (sign * num);
}

p_node *node_init(int num)
{
	p_node *tmp;

	tmp = (p_node *)malloc(sizeof(p_node));
	tmp->data = num;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

p_deq *stack_init()
{
	p_deq *tmp;

	tmp = (p_deq *)malloc(sizeof(p_deq));
	tmp->size = 0;
	tmp->top = NULL;
	tmp->bottom = NULL;
	return (tmp);
}

void push_node_to_stack(p_deq *stack, p_node *new, int idx)
{
	if (idx == 1)
		stack->top = new;
	else if (idx == 2)
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

void print_stack(p_deq *stack)
{
	p_node *tmp;

	tmp = stack->top;
	for (int i = 0; i < stack->size; i++)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

// argc : info cnt, argv : info, 2 1 3 6 5 8
int main(int argc, char *argv[])
{
	p_deq *stack_a;
	p_deq *stack_b;
	p_node *node;
	int		check;
	int		num;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_a = stack_init();
	stack_b = stack_init();
	check = TRUE;
	for (int i = 1; i < argc; i++)
	{
		num = ft_atoi(argv[i], check);
		if (check == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		node = node_init(num);
		push_node_to_stack(stack_a, node, i);
	}
	print_stack(stack_a);
	return (0);
}
