/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:22:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/02/26 20:18:14 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct node
{
	int				data;
	unsigned int	idx;
	struct node		*next;
	struct node		*prev;
}	s_node;

typedef struct deq
{
	int		size;
	s_node *top;
	s_node *bottom;
}	s_deq;

#endif
