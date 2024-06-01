/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 02:05:54 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/01 06:07:13 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define NULL 0

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_release 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdlib.h>

# include "mlx/mlx.h"

# include "0_libft/libft.h"
# include "1_get_next_line/get_next_line.h"
# include "1_ft_printf/ft_printf.h"

typedef struct s_game
{
	int	width;
	int	height;
	char **visited;
	char *map1D;
	char **map2D;
	int Pr;
	int Pc;
	int Er;
	int Ec;
	int C_cnt;
}			t_game;

typedef struct s_data
{
	int	width;
	int	height;
	void	*mlx;
	void	*win;
	void	*img;
	char	*floor;
	char	*goal;
	char	*item;
	char	*player;
	char	*wall;
	int		move;
	int		len;
}				t_data;

int		read_map(int fd, t_game *game);
int		P_E_C_check(t_game *game);
int		box_check(t_game *game);
int 	map_check(char *argv, t_game *game);
int 	visited_setting(t_game *game);
int 	route_check(t_game *game);
void 	dfs(t_game *game, int now_x, int now_y);
void free_game_resources(t_game *game);

char	*get_next_line(int fd);

int 	mlx_map_display(t_game *game);
int 	close_window(t_data *data);
int		key_press(int keycode, t_data *data);
void mlx_initialize(t_data *data);
void mlx_map_to_img(t_game *game, t_data data);


size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_printf(const char *str, ...);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strtrim(const char *s1, const char *set);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
