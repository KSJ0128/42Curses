/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:55:34 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/18 14:40:05 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_initialize(t_game *game)
{
	game->move = 0;
	game->len = 50;
	game->ww = game->len * game->width;
	game->wh = game->len * game->height;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->goal = "img/goal.xpm";
	game->floor = "img/floor.xpm";
	game->item = "img/item.xpm";
	game->player = "img/player.xpm";
	game->wall = "img/wall.xpm";
}

int	close_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	int	check;

	check = 0;
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_UP)
		check = check_for_move(game, 'U');
	else if (keycode == KEY_LEFT)
		check = check_for_move(game, 'L');
	else if (keycode == KEY_DOWN)
		check = check_for_move(game, 'D');
	else if (keycode == KEY_RIGHT)
		check = check_for_move(game, 'R');
	if (check && keycode == KEY_UP)
		collect_end_check(game);
	else if (check && keycode == KEY_LEFT)
		collect_end_check(game);
	else if (check && keycode == KEY_DOWN)
		collect_end_check(game);
	else if (check && keycode == KEY_RIGHT)
		collect_end_check(game);
	return (SUCCESS);
}

int	mlx_map_display(t_game *game)
{
	mlx_initialize(game);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (0);
	game->win = mlx_new_window(game->mlx, game->ww, game->wh, "so_long");
	if (game->win == NULL)
		return (0);
	mlx_map_to_img(*game, game->len);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, close_window, game);
	mlx_loop(game->mlx);
	return (SUCCESS);
}
