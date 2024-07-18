/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:18:03 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/15 15:58:46 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# define ERROR 0
# define SUCCESS 1
# define KO 2
# define MAX 2147483647
# define MIN -2147483648

typedef struct node
{
	int			data;
	struct node	*next;
	struct node	*prev;
}	t_node;

typedef struct stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_deq;

char	*find_next_line(char **backup, char	*n_pos);
int		backup_update(char **backup, char *buff);
int		read_line(int fd, char **backup, int *r_size);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
void	check_sorting(t_deq *stack);
void	run_instruction(t_deq *stack_a, t_deq *stack_b, char *instruction);
int		do_checker(t_deq *stack_a);
void	handle_exception(int err);
int		main(int argc, char *argv[]);
void	free_stack(t_deq *stack);
void	stack_to_array(t_deq *stack);
int		parsing_to_stack(char *argv_num, t_deq *stack);
t_deq	*stack_init(void);

#endif
