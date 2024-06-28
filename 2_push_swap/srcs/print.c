/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:48:59 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/28 12:13:05 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(int *array, int size)
{
	ft_printf("Array\n");
	for (int i = 0; i < size; i++)
		ft_printf("%d ", array[i]);
	ft_printf("\n");
}

void print_stack(const t_deq *stack)
{
    t_node *current = stack->top;

    while (current != NULL)
    {
        ft_printf("%d ", current->data); // 스택의 데이터를 출력
        current = current->next;
    }
    ft_printf("\n");
}
