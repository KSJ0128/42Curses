/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:50:45 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/20 21:58:09 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_deq	*stack_a;
	int		idx;

	if (argc < 2)
		exit(0);
	stack_a = stack_init();
	if (!stack_a)
		exit (0);
	idx = 1;
	while (idx < argc)
	{
		if (!parsing_to_stack(argv[idx], stack_a))
		{
			free_stack(stack_a);
			ft_printf("Error\n");
			exit(0);
		}
		idx++;
	}
	stack_to_array(stack_a);
	ft_printf("정렬 전 스택\n");
	print_stack(stack_a);
	sandglass(stack_a);
	ft_printf("정렬 후 스택\n");
	print_stack(stack_a);
	return (0);
}
