/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:14:55 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/17 13:45:00 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_sorting(t_deq *stack)
{
	t_node	*node;
	int		tmp;

	tmp = stack->top->data;
	if (tmp != 0)
		handle_exception(1);
	node = stack->top->next;
	while (node)
	{
		if (tmp + 1 != node->data)
			handle_exception(1);
		tmp = node->data;
		node = node->next;
	}
}

void	run_instruction(t_deq *stack_a, t_deq *stack_b, char *instruction)
{
	if (ft_strncmp(instruction, "sa\n", 4) == 0)
		swap(stack_a);
	else if (ft_strncmp(instruction, "sb\n", 4) == 0)
		swap(stack_b);
	else if (ft_strncmp(instruction, "ss\n", 4) == 0)
		swap_all(stack_a, stack_b);
	else if (ft_strncmp(instruction, "pa\n", 4) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(instruction, "pb\n", 4) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(instruction, "ra\n", 4) == 0)
		rotate(stack_a);
	else if (ft_strncmp(instruction, "rb\n", 4) == 0)
		rotate(stack_b);
	else if (ft_strncmp(instruction, "rr\n", 4) == 0)
		rotate_all(stack_a, stack_b);
	else if (ft_strncmp(instruction, "rra\n", 5) == 0)
		r_rotate(stack_a);
	else if (ft_strncmp(instruction, "rrb\n", 5) == 0)
		r_rotate(stack_b);
	else if (ft_strncmp(instruction, "rrr\n", 5) == 0)
		r_rotate_all(stack_a, stack_b);
	else
		handle_exception(0);
}

int	do_checker(t_deq *stack_a)
{
	char	*instruction;
	t_deq	*stack_b;

	stack_b = stack_init();
	if (!stack_b)
		exit(1);
	while (1)
	{
		instruction = get_next_line(0);
		if (!instruction)
			break ;
		run_instruction(stack_a, stack_b, instruction);
		free(instruction);
	}
	if (stack_b->size != 0)
		handle_exception(1);
	check_sorting(stack_a);
	free_stack(stack_b);
	return (1);
}

void	handle_exception(int err)
{
	if (err == 0)
		ft_printf("Error\n");
	else if (err == 1)
		ft_printf("KO\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_deq	*stack_a;
	int		idx;

	if (argc < 2)
		exit(0);
	stack_a = stack_init();
	if (!stack_a)
		exit(1);
	idx = 1;
	while (idx < argc)
	{
		parsing_to_stack(argv[idx], stack_a);
		idx++;
	}
	stack_to_array(stack_a);
	if (do_checker(stack_a))
		ft_printf("OK\n");
	else
		handle_exception(1);
	free_stack(stack_a);
	return (0);
}
