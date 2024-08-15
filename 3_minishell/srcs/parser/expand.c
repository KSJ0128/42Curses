// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   expand.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/13 20:17:25 by seojkim           #+#    #+#             */
// /*   Updated: 2024/08/15 21:47:29 by seojkim          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// char	*cmp_var(char *token, char *var)
// {
// 	char	*str;
// 	int		idx;

// 	idx = 0;
// 	while (token[idx] != '\0' && var[idx] != '=')
// 	{
// 		if (token[idx] == var[idx])
// 			idx++;
// 		else
// 			break ;
// 	}
// 	if (token[idx] == '\0' && var[idx] == '=')
// 	{
// 		str = (char *)malloc(idx);
// 		strlcpy(str, var, idx);
// 		return (str);
// 	}
// 	return (NULL);
// }

// void	find_var(char **envp, t_token *token)
// {
// 	char	*var;
// 	char	*tmp;
// 	int		idx;

// 	idx = 0;
// 	while (envp[idx] != NULL)
// 	{
// 		var = cmp_var(token->data, envp[idx]);
// 		if (var)
// 		{
// 			tmp = token->data;
// 			token->data = var;
// 			free(tmp);
// 		}
// 		idx++;
// 	}
// }

// void	expand_var(char **envp, t_envi *envi)
// {
// 	t_token	*now;

// 	now = envi->tokens;
// 	while (now != NULL)
// 	{
// 		find_var(envp, now);
// 		now = now->next;
// 	}
// }