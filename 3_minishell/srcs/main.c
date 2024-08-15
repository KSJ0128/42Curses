/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:32:58 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/15 22:23:37 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:32:58 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/15 02:58:24 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setting_envi(t_envi *envi)
{
    envi->tokens = (t_token *)malloc(sizeof(t_token));
	if (!(envi->tokens))
		exit(1);
	envi->tokens->data = NULL;
	envi->tokens->next = NULL;
	envi->quote[SINGLE] = 0;
	envi->quote[DOUBLE] = 0;
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	t_envi			*envi;

	(void)argv;
	(void)envp;
	if (argc != 1)
		handle_error(0);
	envi = (t_envi *)malloc(sizeof(t_envi));
	while (1)
	{
		line = readline("\033[35mminishell$>\033[0m ");
		setting_envi(envi);
		if (line)
		{
			add_history(line);
			if (!check_quote(line, envi))
				handle_error(1);
			tokenize(line, envp, envi);
			int idx = 0;
	t_token	*now;
	now = envi->tokens;
	while (now != NULL)
	{
		printf("Token[%d] : %s\n", idx, now->data);
		now = now->next;
		idx++;
	}
		}
	}
	return (0);
}
