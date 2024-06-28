/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:22:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/28 13:29:14 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#define SUCCESS 1
#define ERROR 0
#define MAX 2147483647
#define MIN -2147483648

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} t_node;

typedef struct stack
{
	int size;
	t_node *top;
	t_node *bottom;
} t_deq;

long long	ft_atoll(const char *str);
void		swap(t_deq *stack);
void		swap_all(t_deq *p, t_deq *q);
void		push_p(t_deq *p, t_deq *q);
void		push_q(t_deq *p, t_deq *q, t_node *p_top);
void		rotate(t_deq *stack);
void		rotate_all(t_deq *p, t_deq *q);
void		r_rotate(t_deq *stack);
void		r_rotate_all(t_deq *p, t_deq *q);
t_node		*node_init(int num);
t_deq		*stack_init(void);
void 		stack_setting(t_deq *stack, int num);
void 		free_stack(t_deq *stack);
int			parsing_to_stack(char *argv_str, t_deq *stack);
void		stack_to_array(t_deq *stack);
void		sorting_array(int *array, int s, int e);
void		indexing_stack(t_deq *stack, int *array);
t_node		*find_data(t_deq *stack, int *array, int idx);
void		overlap_check(int *array, int size);
void		sorting_a(t_deq *stack_a);
void		push_a_to_b(t_deq *stack_a, t_deq *stack_b, int pivot_a, int pivot_b);
void		greedy(t_deq *stack_a);
int			main(int argc, char *argv[]);
void		print_array(int *array, int size);
void		print_stack(const t_deq *stack);
char		*ps_strdup_size(char *src, int size);
void		ps_free_split(char **split, int k);
long long	ps_word_count(char *str, char c);
int			ps_insert_word(char **split, char *str, char c);
char		**ps_split(char *str, char c, long long *stack_size);
void		handle_exception(int err);
void		sorting_two(t_deq *stack_a);
void		sorting_three_one(t_deq *stack_a);
void		sorting_three_two(t_deq *stack_a);
void		sorting_a(t_deq *stack_a);
int			searching_b(const t_deq *stack_a, const t_deq *stack_b, int roll_b, int *roll_a);
void	optimize_a_b(t_deq *stack_a, t_deq *stack_b, int roll_b, int roll_a);
void	optimize_a(t_deq *stack_a, int roll_a);
void	optimize_b(t_deq *stack_b, int roll_b);
void	roll_a_b(t_deq *stack_a, t_deq *stack_b, int roll_b, int roll_a);

#endif
