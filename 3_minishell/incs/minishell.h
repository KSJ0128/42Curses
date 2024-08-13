/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:33:42 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/13 21:10:30 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include "libft.h"
#include "readline.h"
#include "history.h"

typedef struct quote
{
	char	data;
	void	*next;
}	t_quote;

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
void	pipe_parsing(char *str);

#endif