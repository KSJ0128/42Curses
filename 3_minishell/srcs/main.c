/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:32:58 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/13 21:11:27 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	// t_process	*process;

	(void)argv;
	(void)envp;
	if (argc != 1)
		handle_error(0);
	while (1)
	{
		line = readline("minishell$>");
		if (line)
		{
			add_history(line);
			if (!quote_check(line))
				handle_error(1);
			pipe_parsing(line);

		}
	}
	return (0);
}
