/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:22:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/04 20:12:02 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# define TRUE 1

typedef struct node
{
	int				data;
	unsigned int	idx;
	struct node		*next;
	struct node		*prev;
}	p_node;

typedef struct deq
{
	int		size;
	p_node *top;
	p_node *bottom;
}	p_deq;

typedef struct push_swap
{
	p_deq a;
	p_deq b;
}	p_push_swap;

int		ft_atoi(const char *str, int check);
p_node	*node_init(int num);
p_deq	*stack_init();
void	push_node_to_stack(p_deq *stack, p_node *new, int idx);
void	print_stack(p_deq *stack);
int		main(int argc, char *argv[]);
void	swap(p_deq *stack);
void	swap_all(p_deq *p, p_deq *q);
void	push(p_deq *p, p_deq *q);
void	rotate(p_deq *stack);
void	rotate_all(p_deq *p, p_deq *q);
void 	r_rotate(p_deq *stack);
void 	r_rotate_all(p_deq *p, p_deq *q);

#endif
