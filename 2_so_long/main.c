/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 02:05:22 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/01 17:28:09 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_game_resources(t_game *game)
{
    if (game->map1D)
		free(game->map1D);
    if (game->map2D)
    {
        for (int i = 0; game->map2D[i]; i++)
            free(game->map2D[i]);
        free(game->map2D);
    }
	if (game->visited)
	{
		for (int i = 0; game->visited[i]; i++)
			free(game->visited[i]);
		free(game->visited);
	}
	if (game)
		free(game);
}

int main(int argc, char *argv[])
{
	t_game	*game;
	t_data  data;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	if (!map_check(argv[argc - 1], game))
	{
		free_game_resources(game);
		return (NULL);
	}
	if (!route_check(game))
	{
		free_game_resources(game);
		return (NULL);
	}
	ft_printf(game->map1D);
	mlx_map_display(game);
	free_game_resources(game);
	return (0);
}
