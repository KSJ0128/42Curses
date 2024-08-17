/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:07:27 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/17 22:00:33 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// start ~ idx - 1까지의 토큰 추가
void	add_token(char *line, t_envi *envi, int start, int idx)
{
	t_token	*now;
	t_token	*token;
	char	*str;

	str = ft_strndup(line + start, idx - start);
	if (!str)
		handle_error(-1);
	now = envi->tokens;
	if (now->data == NULL)
		now->data = str;
	else
	{
		token = (t_token *)malloc(sizeof(t_token));
		if (!token)
			handle_error(-1);
		token->data = str;
		token->next = NULL;
		while (now->next != NULL)
			now = now->next;
		now->next = token;
	}
}

void	tokenize(char *line, t_envi *envi)
{
	int	start;
	int	idx;

	start = 0;
	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] == '\'' || line[idx] == '\"')
			is_quote(line[idx], envi);
		else if (is_deli(line, envi, idx))
		{
			if (start < idx)
				add_token(line, envi, start, idx); // 구분자 앞에 문자열 존재시 단어 토큰 추가
			if (check_deli(line, envi, idx, idx))
				start = idx + 1;
			else
				start = idx + 2;
			idx = start - 1;
		}
		idx++;
	}
	add_token(line, envi, start, idx); // 구분자 앞에 문자열 존재시 단어 토큰 추가
}
