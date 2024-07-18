/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:50:45 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/17 13:45:08 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_exception(int err)
{
	if (err == 0)
		ft_printf("Error\n");
	exit(0);
}

int	need_sort_check(t_deq *stack)
{
	t_node	*node;
	int		tmp;

	tmp = stack->top->data;
	if (tmp != 0)
		return (SUCCESS);
	node = stack->top->next;
	while (node)
	{
		if (tmp + 1 != node->data)
			return (SUCCESS);
		tmp = node->data;
		node = node->next;
	}
	return (ERROR);
}

int	main(int argc, char *argv[])
{
	t_deq	*stack_a;
	int		idx;

	if (argc < 2)
		exit(0);
	stack_a = stack_init();
	idx = 1;
	while (idx < argc)
	{
		parsing_to_stack(argv[idx], stack_a);
		idx++;
	}
	if (stack_a->size == 1)
		exit(0);
	stack_to_array(stack_a);
	if (stack_a->size == 2)
		sorting_two(stack_a);
	else if (stack_a->size == 3)
		sorting_three_one(stack_a);
	if (need_sort_check(stack_a))
		greedy(stack_a);
	free_stack(stack_a);
	return (0);
}
