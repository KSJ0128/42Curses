/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:22:08 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/15 13:47:56 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#define ERROR 0
#define SUCCESS 1
#define KO 2
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

typedef struct command
{
	int roll_a;
	int roll_b;
	int total_roll;
} t_cmd;

void		swap(t_deq *stack);
void		swap_all(t_deq *p, t_deq *q);
void		push(t_deq *throw, t_deq *catch);
void		rotate(t_deq *stack);
void		rotate_all(t_deq *p, t_deq *q);
void		r_rotate(t_deq *stack);
void		r_rotate_all(t_deq *p, t_deq *q);
long long	ft_atoll(const char *str);
void		do_cmd(t_deq *stack_a, t_deq *stack_b, t_cmd *cmd);
int			counting_cmd_top(const t_deq *stack_a, int x);
int			counting_cmd(const t_deq *stack_a, int x);
int			searching_b(t_deq *stack_a, t_deq *stack_b, int roll_b);
void		greedy(t_deq *stack_a);
void		handle_exception(int err);
int			main(int argc, char *argv[]);
void		optimize_a_b(t_deq *stack_a, t_deq *stack_b, int roll_a, int roll_b);
void		optimize_a(t_deq *stack_a, t_deq *stack_b, int roll_a, int roll_b);
void		optimize_b(t_deq *stack_a, t_deq *stack_b, int roll_a, int roll_b);
void		roll_a_b(t_deq *stack_a, t_deq *stack_b, int roll_a, int roll_b);
int 		optimize_cmd(t_deq *stack_a, t_deq *stack_b, int total, int roll_b);
void		final_sort(t_deq *stack_a);
void 		sorting_two(t_deq *stack_a);
void 		sorting_three_one(t_deq *stack_a);
void 		sorting_three_two(t_deq *stack_a);
void 		sorting_a(t_deq *stack_a);
char		*ps_strdup_size(char *src, int size);
void		ps_free_split(char **split, int k);
long long	ps_word_count(char *str, char c);
int			ps_insert_word(char **split, char *str, char c);
char		**ps_split(char *str, char c, long long *stack_size);
void		push_b_to_a(t_deq *stack_a, t_deq *stack_b);
void		push_a_to_b(t_deq *stack_a, t_deq *stack_b, int pivot_a, int pivot_b);
t_node		*node_init(int num);
t_deq		*stack_init(void);
void 		free_stack(t_deq *stack);
void 		stack_setting(t_deq *stack, int num);
int			parsing_to_stack(char *argv_str, t_deq *stack);
t_node		*find_data(t_deq *stack, int *array, int idx);
void		indexing_stack(t_deq *stack, int *array);
void		overlap_check(int *array, int size);
void		sorting_array(int *array, int s, int e);
void		stack_to_array(t_deq *stack);
void		push_top(t_deq *stack, t_node *node);
void		push_bottom(t_deq *stack, t_node *node);
t_node		*pop_top(t_deq *stack);
t_node		*pop_bottom(t_deq *stack);
void		print_array(int *array, int size);
void		print_stack(const t_deq *stack);
int			need_sort_check(t_deq *stack);

#endif
