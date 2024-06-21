/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_pec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:19:41 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/18 14:31:59 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player(t_game *game, int r)
{
	int	c;

	c = 0;
	while (game->map[r][c] != '\0')
	{
		if (game->map[r][c] == 'P')
		{
			if (game->p_check == 1)
				return (0);
			game->pr = r;
			game->pc = c;
			game->p_check = 1;
		}
		c++;
	}
	return (SUCCESS);
}

int	find_end(t_game *game, int r)
{
	int	c;

	c = 0;
	while (game->map[r][c] != '\0')
	{
		if (game->map[r][c] == 'E')
		{
			if (game->e_check == 1)
				return (0);
			game->er = r;
			game->ec = c;
			game->e_check = 1;
		}
		c++;
	}
	return (SUCCESS);
}

void	find_c(t_game *game, int r)
{
	int	c;

	c = 0;
	while (game->map[r][c] != '\0')
	{
		if (game->map[r][c] == 'C')
			game->c_cnt++;
		c++;
	}
}

int	p_e_c_check(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx < game->height)
	{
		if (!find_player(game, idx))
			return (0);
		if (!find_end(game, idx))
			return (0);
		find_c(game, idx);
		idx++;
	}
	if (game->p_check != 1 || game->e_check != 1 || game->c_cnt < 1)
		return (0);
	return (SUCCESS);
}

int	check_valid_pec(t_game *game)
{
	game->p_check = 0;
	game->e_check = 0;
	game->c_cnt = 0;
	if (!p_e_c_check(game))
		handle_exception(3);
	return (SUCCESS);
}
