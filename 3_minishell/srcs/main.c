/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:32:58 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/17 22:05:29 by seojkim          ###   ########.fr       */
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
}

void	setting_etc(t_envi *envi)
{
	envi->quote[SINGLE] = 0;
	envi->quote[DOUBLE] = 0;
	envi->out_quote = NULL;
	envi->paren[SMALL] = 0;
	envi->paren[MIDEUM] = 0;
}

void	remove_quote(t_envi *envi)
{
	t_token *now;
	char	*str;
	char	*tmp;
	int		tmp_idx;
	int		idx;

	now = envi->tokens;
	while (now != NULL)
	{
		str = now->data;
		tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!tmp)
			handle_error(-1);
		idx = 0;
		tmp_idx = 0;
		while (str[idx] != '\0')
		{
			if (str[idx] != '\'' && str[idx] != '\"')
				tmp[tmp_idx++] = str[idx];
			idx++;
		}
		tmp[tmp_idx] = '\0';
		change_data(now, tmp);
		now = now->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	t_envi			*envi;

	(void)argv;
	// (void)envp;
	if (argc != 1)
		handle_error(0);
	envi = (t_envi *)malloc(sizeof(t_envi));
	if (!envi)
		handle_error(-1);
	while (1)
	{
		line = readline("\033[34mminishell$>\033[0m ");
		setting_envi(envi);
		setting_etc(envi);
		if (line)
		{
			add_history(line);
			if (!check_quote(line, envi))
				handle_error(1);
			tokenize(line, envi);
			expand_var(envp, envi);
			// remove_quote(envi);
			t_token *now = envi->tokens;
			while (now != NULL) {
				printf("%s\n", now->data);
				now = now->next;
			}
		}
	}
	free_envi(envi);
	return (0);
}

//"asdf" asdf | sdf <sdf>> asdf | $USER
//"asd   as"asd   asdf"'zsdfa'|  asdf  <sdfa>>adf | asdf | |