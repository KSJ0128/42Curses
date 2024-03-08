/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:22:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/08 20:32:46 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# define TRUE 1
# define ERROR -1
# define NONE_INTEGER 99999999999

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

size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *s);
long long	ft_atoll(const char *str);
char		**ft_split(char *str, char c, int *word_cnt);
char		*ft_strdup_size(char *src, int size);
void		free_split(char **split, int k);
int			word_count(char *str, char c);
int			insert_word(char **split, char *str, char c);
void		swap(p_deq *stack);
void		swap_all(p_deq *p, p_deq *q);
void		push(p_deq *p, p_deq *q);
void		rotate(p_deq *stack);
void		rotate_all(p_deq *p, p_deq *q);
void 		r_rotate(p_deq *stack);
void 		r_rotate_all(p_deq *p, p_deq *q);
p_node		*node_init(int num);
p_deq		*stack_init();
void		push_node_to_stack(p_deq *stack, int num);
void		free_stack(p_deq *stack);
int 		parsing_to_stack(char *argv_str, p_deq *stack);
void 		stack_to_array(p_deq *stack);
void 		sorting_array(int *array, int s, int e);
void 		indexing_stack(p_deq *stack, int *array);
p_node 		*find_data(p_deq *stack, int *array, int idx);
void 		overlap_check(p_deq *stack, int *array, int size);
int			main(int argc, char *argv[]);
void		print_stack(p_deq *stack);
void 		print_array(int *array, int size);

#endif
