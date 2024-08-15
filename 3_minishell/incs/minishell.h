/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:33:42 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/15 22:21:10 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SUCCESS 1
# define NULL 0
# define TRUE 1
# define FALSE 0

# define SINGLE 0
# define DOUBLE 1

# define DELI_REDIR 0
# define DELI_ETC 1

# define ERROR_QUOTE 0

#include <stdio.h>
#include "libft.h"
#include "readline.h"
#include "history.h"

typedef struct token
{
	char	*data;
	struct token	*next;
}	t_token;

typedef struct envi
{
	t_token	*tokens;
	int		quote[2];
}	t_envi;

typedef struct file
{
	void	*next;
	char	*data;
}	t_file;

typedef struct redir
{
	void	*next;
	int		type;
	char	*data;
}	t_redir;

typedef struct process
{
	t_file		*files;
	t_redir		*redirs;
}	t_process;

void	handle_error(int num);
int		check_quote(char *line, t_envi *envi);
void	is_quote(char c, t_envi *envi);
int		is_deli(char *line, t_envi *envi, int idx);
int		check_deli(char *line, t_envi *envi, int start, int idx);
void	delete_empty_token(t_envi *tokens);
void	add_token(char *line, t_envi *envi, int start, int idx);
void	tokenize(char *line, char **envp, t_envi *envi);
void	expand_var(char **envp, t_envi *envi);

#endif


//   "   "|asf<sdf>>asdfasdfasd   |
//    "asfafd<adf>'  'asdf"<asdfa>>asdfasdf | adfas||
/*
//
토큰 출력 테스트
	int idx = 0;
	t_token	*now;
	now = envi->tokens;
	while (now != NULL)
	{
		printf("Token[%d] : %s\n", idx, now->data);
		now = now->next;
		idx++;
	}
*/