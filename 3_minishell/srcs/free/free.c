/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:54:32 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/17 22:04:52 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_data(t_token *token, char *str)
{
	free(token->data);
	token->data = str;
}

void	free_tokens(t_token *tokens)
{
	t_token *now;

	now = tokens;
	while (now != NULL)
	{
		free(now->data);
		now = now->next;
	}
}

void	free_envi(t_envi *envi)
{
	free_tokens(envi->tokens);
	free(envi);
}