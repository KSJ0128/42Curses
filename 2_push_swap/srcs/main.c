/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:50:45 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/28 12:33:58 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_exception(int err)
{
	if (err == 0)
		ft_printf("Error\nInvalid argument.\n");
	else if (err == 1)
		ft_printf("Error\nInvalid number.\n");
	
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_deq	*stack_a;
	int		idx;

	if (argc < 2)
		handle_exception(0);
	else if (argc == 2)
		exit(0);
	stack_a = stack_init();
	idx = 1;
	while (idx < argc)
	{
		parsing_to_stack(argv[idx], stack_a);
		idx++;
	}
	stack_to_array(stack_a);
	if (stack_a->size == 2)
		sorting_two(stack_a);
	else if (stack_a->size == 3)
		sorting_three_one(stack_a);
	else
		greedy(stack_a);
	// print_stack(stack_a);
	return (0);
}
