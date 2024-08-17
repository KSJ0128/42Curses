/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:17:25 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/17 22:34:45 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_var(char c)
{
	if (c == '-')
		return (FALSE);
	if (c >= 'a' && c <= 'z')
		return (FALSE);
	if (c >= 'A' && c <= 'Z')
		return (FALSE);
	if (c >= '0' && c <= '9')
		return (FALSE);
	return (TRUE);
}

void	change_var(t_token *token, char *var, int d_idx)
{
	char	*new;

	new = ft_strdup("");
	if (!new)
		handle_error(-1);
	ft_strlcat(new, token->data, d_idx + 1);
	ft_strlcat(new, var, ft_strlen(var) + 1);
	ft_strlcat(new, token->data + d_idx + 1, ft_strlen(token->data + d_idx) + 1);
	change_data(token, new);
}

void	can_change_var(char **envp, t_token *token, char *str, int d_idx)
{
	char	**ptr;
	char	*var;
	int		idx;

	ptr = envp;
	while (*ptr != NULL)
	{
		var = *ptr;
		idx = 0;
		if (str[idx] == '{')
			idx++;
		while (str[idx] == var[idx] && var[idx] != '=' && str[idx] != '\0')
			idx++;
		if (var[idx] == '=' && is_var(str[idx]))
			change_var(token, var + idx + 1, d_idx);
		ptr++;
	}
}

// 확장 조건 만족하는 토큰인 경우 변환 함수로 넘겨줌
void	expand_var(char **envp, t_envi *envi)
{
	t_token	*now;
	char	*str;
	int		idx;

(void)envp;
	now = envi->tokens;
	while (now != NULL)
	{
		str = now->data;
		idx = 0;
		setting_etc(envi);
		while (str[idx] != '\0')
		{
			if ((str[idx] == '\'' || str[idx] == '\"') \
			&& is_quote(str[idx], envi))
				set_out_quote(str[idx], envi);
			else if (str[idx] == '$' && envi->out_quote != '\'')
				can_change_var(envp, now, str + idx + 1, idx + 1); // token에 $ 있고, 환경변수 확장 조건 충족하는지 확인
			idx++;
		}
		now = now->next;
	}
}
