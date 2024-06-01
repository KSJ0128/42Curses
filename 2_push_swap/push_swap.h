/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:22:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/03/20 20:15:32 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# define SUCCESS 1
# define ERROR 0
# define NONE_INTEGER 99999999999

typedef struct node
{
	int				data;
	struct node		*next;
	struct node		*prev;
}	t_node;

typedef struct stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_deq;

size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *s);
long long	ft_atoll(const char *str);
char		**ft_split(char *str, char c, int *word_cnt);
char		*ft_strdup_size(char *src, int size);
void		free_split(char **split, int k);
int			word_count(char *str, char c);
int			insert_word(char **split, char *str, char c);
void		swap(t_deq *stack);
void		swap_all(t_deq *p, t_deq *q);
void		push(t_deq *p, t_deq *q);
void		rotate(t_deq *stack);
void		rotate_all(t_deq *p, t_deq *q);
void		r_rotate(t_deq *stack);
void		r_rotate_all(t_deq *p, t_deq *q);
t_node		*node_init(int num);
t_deq		*stack_init();
void		stack_a_setting(t_deq *stack, int num);
void		free_stack(t_deq *stack);
int			parsing_to_stack(char *argv_str, t_deq *stack);
void		stack_to_array(t_deq *stack);
void		sorting_array(int *array, int s, int e);
void		indexing_stack(t_deq *stack, int *array);
t_node		*find_data(t_deq *stack, int *array, int idx);
void		overlap_check(t_deq *stack, int *array, int size);
void		push_a_to_b(t_deq *a, t_deq *b);
void		sandglass(t_deq *stack_a);
int			main(int argc, char *argv[]);
void		print_array(int *array, int size);
void 		print_stack(t_deq *stack);

#endif
