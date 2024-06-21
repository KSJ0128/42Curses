/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 02:05:54 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/18 14:40:20 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TRUE 1
# define SUCCESS 1
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_game
{
	int		width;
	int		height;
	int		ww;
	int		wh;
	char	**visited;
	char	**map;
	int		p_check;
	int		pr;
	int		pc;
	int		e_check;
	int		er;
	int		ec;
	int		c_cnt;
	int		move;
	int		len;
	void	*mlx;
	void	*win;
	void	*img;
	char	*floor;
	char	*goal;
	char	*item;
	char	*player;
	char	*wall;
}				t_game;

int		handle_exception(int err);
int		check_valid_map(t_game *game);
void	remove_new_line(t_game *game);
int		check_width(t_game *game);
int		check_top_bottom(t_game *game);
int		check_side(t_game *game);
int		check_valid_pec(t_game *game);
int		p_e_c_check(t_game *game);
int		find_player(t_game *game, int r);
int		find_end(t_game *game, int r);
void	find_c(t_game *game, int r);
int		visited_setting(t_game *game);
int		route_check(t_game *game);
void	dfs(t_game *game, int now_x, int now_y, int *check_c);
char	*get_next_line(int fd);
int		mlx_map_display(t_game *game);
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);
void	mlx_initialize(t_game *game);
void	mlx_map_to_img(t_game game, int len);
int		check_for_move(t_game *game, char c);
void	collect_end_check(t_game *game);
void	free_split(char **split, int k);

#endif
