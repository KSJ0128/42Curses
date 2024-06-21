/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:03:13 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/18 14:32:08 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_bottom(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx < game->width)
	{
		if (game->map[0][idx] != '1')
			return (0);
		if (game->map[game->height - 1][idx] != '1')
			return (0);
		idx++;
	}
	return (SUCCESS);
}

int	check_side(t_game *game)
{
	int	idx;

	idx = 1;
	while (idx < game->height - 1)
	{
		if (game->map[idx][0] != '1')
			return (0);
		if (game->map[idx][game->width - 1] != '1')
			return (0);
		idx++;
	}
	return (SUCCESS);
}

int	check_width(t_game *game)
{
	int	idx;

	remove_new_line(game);
	idx = 1;
	game->width = ft_strlen(game->map[0]);
	while (idx < game->height)
	{
		if ((int)ft_strlen(game->map[idx]) != game->width)
			return (0);
		idx++;
	}
	return (SUCCESS);
}

void	remove_new_line(t_game *game)
{
	int	idx;
	int	len;

	idx = 0;
	while (idx < game->height)
	{
		len = ft_strlen(game->map[idx]) - 1;
		if (game->map[idx][len] == '\n')
			game->map[idx][len] = '\0';
		idx++;
	}
}

int	check_valid_map(t_game *game)
{
	if (!check_width(game) || !check_top_bottom(game) || !check_side(game))
		handle_exception(2);
	return (SUCCESS);
}
