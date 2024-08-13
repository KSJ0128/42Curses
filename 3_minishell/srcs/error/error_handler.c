/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:18:59 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/13 21:12:27 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_error(int num)
{
	if (num == 0)
		printf("Error : Invalid arguments.\n");
	else if (num == 0)
		printf("Error : Invalid quotes.\n");
	exit(0);
}

int	quote_check(char *line)
{
	t_quote	*stack;
	int		idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		
	}

}
