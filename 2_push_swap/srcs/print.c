/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:48:59 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/22 20:59:02 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	ft_printf("Array\n");
	for (int i = 0; i < size; i++)
		ft_printf("%d ", array[i]);
	ft_printf("\n");
}

void print_stack(t_deq *stack)
{
	t_node *tmp  = stack->top;

	ft_printf("Stack\n");
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
