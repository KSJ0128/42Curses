/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:07:27 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/13 21:11:04 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quote(char *str)
{
	int		idx;
	quote	*stack;

	idx = 0;
	while (str[idx] != '\0')
	{

	}
}

void	pipe_parsing(char *str)
{
	char	**lines;
	char	**tokens;
	int		idx;

	idx = 0;
	lines = ft_split(str, '|');
	while (lines[idx] != NULL)
	{
		tokens = ft_split(lines[idx], ' ');
		int i = 0;
		while (tokens[i] != NULL)
		{
			printf("%s\n", tokens[i]);
			i++;
		}
		idx++;
	}
	setting_process(lines);
}
