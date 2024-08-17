/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synctax_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:17:20 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/17 20:56:26 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_out_quote(char quote, t_envi *envi)
{
	if (envi->quote[SINGLE] == 0 && envi->quote[DOUBLE] == 0)
		return ;
	else if (envi->quote[SINGLE] == 1 && envi->quote[DOUBLE] == 1)
	{
		if (quote == '\'')
			envi->out_quote = '\"';
		else
			envi->out_quote = '\'';
	}
	else
		envi->out_quote = quote;
}

// 따옴표 쌍 확인
int	check_quote(char *line, t_envi *envi)
{
	int	idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] == '\'' && !(envi->quote[DOUBLE]))
			envi->quote[SINGLE] ^= 1;
		else if (line[idx] == '\"' && !(envi->quote[SINGLE]))
			envi->quote[DOUBLE] ^= 1;
		idx++;
	}
	if (envi->quote[SINGLE] || envi->quote[DOUBLE])
		return (ERROR_QUOTE);
	return (SUCCESS);
}

// 따옴표 상태 반영
int	is_quote(char c, t_envi *envi)
{
	if (c == '\'' && !(envi->quote[DOUBLE]))
	{
		envi->quote[SINGLE] ^= 1;
		return (SUCCESS);
	}
	else if (c == '\"' && !(envi->quote[SINGLE]))
	{
		envi->quote[DOUBLE] ^= 1;
		return (SUCCESS);
	}
	return (FALSE);
}

// 구분자인지 확인
int	is_deli(char *line, t_envi *envi, int idx)
{
	if (envi->quote[SINGLE] || envi->quote[DOUBLE])
		return (FALSE);
	if ((line[idx] >= 9 && line[idx] <= 13) || line[idx] == 32)
		return (TRUE);
	else if (line[idx] == ' ' || line[idx] == '|' || line[idx] == '<' || \
		line[idx] == '>' || line[idx] == '\0')
		return (TRUE);
	return (FALSE);
}

// 어떤 구분자인지 확인 후 구분자 토큰 추가
int	check_deli(char *line, t_envi *envi, int start, int idx)
{
	if ((line[idx] == '<' && line[idx + 1] == '<') || \
		(line[idx] == '>' && line[idx + 1] == '>'))
	{
		add_token(line, envi, start, idx + 2);
		return (DELI_REDIR);
	}
	else if (line[idx] == '|' || line[idx] == '<' || line[idx] == '>')
	{
		add_token(line, envi, idx, idx + 1);
		return (DELI_ETC);
	}
	return (DELI_ETC);
}

// $USER | {$USER | {$USER} | ${USER} | "$USER" | '$USER' | '"$USER"' | "'$USER'" | $"USER"