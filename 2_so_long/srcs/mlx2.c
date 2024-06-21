/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:19:20 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/17 21:32:21 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_move(t_game *game, char c)
{
	if (game->map[game->pr][game->pc] != 'E')
		game->map[game->pr][game->pc] = '0';
	if (c == 'U' && game->map[game->pr - 1][game->pc] != '1')
		game->pr--;
	else if (c == 'L' && game->map[game->pr][game->pc - 1] != '1')
		game->pc--;
	else if (c == 'D' && game->map[game->pr + 1][game->pc] != '1')
		game->pr++;
	else if (c == 'R' && game->map[game->pr][game->pc + 1] != '1')
		game->pc++;
	else
		return (0);
	return (SUCCESS);
}

void	collect_end_check(t_game *game)
{
	game->move++;
	ft_printf("Moving Step : %d\n", game->move);
	if (game->map[game->pr][game->pc] == 'C')
	{
		game->c_cnt--;
		game->map[game->pr][game->pc] = '0';
	}
	else if (game->map[game->pr][game->pc] == 'E')
	{
		if (game->c_cnt == 0)
			close_window(game);
	}
	mlx_map_to_img(*game, game->len);
	if (game->map[game->pr][game->pc] != 'E')
		game->map[game->pr][game->pc] = 'P';
	game->img = mlx_xpm_file_to_image(game->mlx, game->player, \
										&(game->len), &(game->len));
	mlx_put_image_to_window(game->mlx, game->win, game->img, \
								game->len * game->pc, game->len * game->pr);
}

void	img_setting(t_game *game, int w, int h, int len)
{
	game->img = mlx_xpm_file_to_image(game->mlx, game->floor, &len, &len);
	mlx_put_image_to_window(game->mlx, game->win, game->img, len * w, len * h);
	if (game->map[h][w] == '1')
		game->img = mlx_xpm_file_to_image(game->mlx, game->wall, &len, &len);
	else if (game->map[h][w] == 'P')
		game->img = mlx_xpm_file_to_image(game->mlx, game->player, &len, &len);
	else if (game->map[h][w] == 'C')
		game->img = mlx_xpm_file_to_image(game->mlx, game->item, &len, &len);
	else if (game->map[h][w] == 'E')
		game->img = mlx_xpm_file_to_image(game->mlx, game->goal, &len, &len);
	mlx_put_image_to_window(game->mlx, game->win, game->img, len * w, len * h);
}

void	mlx_map_to_img(t_game game, int len)
{
	int	w;
	int	h;

	h = 0;
	while (h < game.height)
	{
		w = 0;
		while (w < game.width)
		{
			img_setting(&game, w, h, len);
			w++;
		}
		h++;
	}
}
