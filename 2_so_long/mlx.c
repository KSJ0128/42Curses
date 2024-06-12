/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:55:34 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/12 20:43:07 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;
// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	key_hook(int keycode, t_data *img) // 키 누르면 메시지 출력, 궁금한 건 특정 키 대상으로는 어떻게 ?
// {
// 	if (keycode == 53)
// 		mlx_destroy_window(img->mlx, img->win);
// 	else
// 		printf("Hello from key_hook!\n");
// 	return (0);
// }

// int	mouse_hook(int button, int x, int y, void *params) // 키 누르면 메시지 출력, 궁금한 건 특정 키 대상으로는 어떻게 ?
// {
// 	printf("Hello from mouse_hook!\n");
// 	return (0);
// }

void mlx_initialize(t_data *data)
{
	data->move = 0; // 움직인 횟수
	data->len = 50; // 이미지 픽셀 한 개 길이
	data->mlx = NULL;
    data->win = NULL;
    data->img = NULL;
    data->goal = "img/goal.xpm";
	data->floor = "img/floor.xpm";
	data->item = "img/item.xpm";
	data->player = "img/player.xpm";
	data->wall = "img/wall.xpm";
}

int close_window(t_data *data)
{
	if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    exit(0); // 정상 종료
    return (NULL);
}

int	key_press(int keycode, t_data *data)
{
	int check;

    if (keycode == KEY_W)
		check = check_for_move(data, 'W');
	else if (keycode == KEY_A)
		check = check_for_move(data, 'A');
	else if (keycode == KEY_S)
		check = check_for_move(data, 'S');
	else if (keycode == KEY_D)
		check = check_for_move(data, 'D');
	else if (keycode == KEY_ESC)
		close_window(data);
	if (check && keycode == KEY_W)
		collect_end_check(data, 'W');
	else if (check && keycode == KEY_A)
		collect_end_check(data, 'A');
	else if (check && keycode == KEY_S)
		collect_end_check(data, 'S');
	else if (check && keycode == KEY_D)
		collect_end_check(data, 'D');
	return (SUCCESS);
}
// map -> mlx setting
void mlx_map_to_img(t_data data)
{
	int w;
	int h;

	h = 0;
	while (h < data.height)
	{
		w = 0;
		while (w < data.width)
		{
			data.img = mlx_xpm_file_to_image(data.mlx, data.floor, &data.len, &data.len);
			mlx_put_image_to_window(data.mlx, data.win, data.img, data.len * w, data.len * h);
			if (data.map2D[h][w] == '1')
				data.img = mlx_xpm_file_to_image(data.mlx, data.wall, &data.len, &data.len);
			else if (data.map2D[h][w] == 'P')
				data.img = mlx_xpm_file_to_image(data.mlx, data.player, &data.len, &data.len);
			else if (data.map2D[h][w] == 'C')
				data.img = mlx_xpm_file_to_image(data.mlx, data.item, &data.len, &data.len);
			else if (data.map2D[h][w] == 'E')
				data.img = mlx_xpm_file_to_image(data.mlx, data.goal, &data.len, &data.len);
			mlx_put_image_to_window(data.mlx, data.win, data.img, data.len * w, data.len * h);
			w++;
		}
		h++;
	}
}

int mlx_map_display(t_data *data)
{
	mlx_initialize(data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (NULL);
    data->win = mlx_new_window(data->mlx, (data->width - 1) * data->len, data->height * data->len, "so_long");
	if (data->win == NULL)
		return (NULL);
	mlx_map_to_img(*data);
	mlx_key_hook(data->win, key_press, data); // 키 훅 함수 등록 (키 누름 이벤트)
	mlx_hook(data->win, X_EVENT_KEY_EXIT, 0, close_window, data);
	mlx_loop(data->mlx);
	return (SUCCESS);
}

/*
	mlx_hook의 x_mask 인수는 쓸모가 없으므로 0으로 유지

	X11 이벤트 :
	ON_KEYDOWN = 2
	ON_KEYUP = 3
	ON_MOUSEDOWN = 4
	ON_MOUSEUP = 5
	ON_MOUSEMOVE = 6
	ON_EXPOSE = 12
	ON_DESTROY = 17

	MacOS용 키 코드:
	esc: 53
	W,A,S,D: 13, 0, 1, 2
	up,left,down,right: 126, 123, 125, 124

	MacOS용 마우스 코드:
	왼쪽 클릭: 1
	마우스 오른쪽 버튼 클릭: 2
	가운데 클릭: 3
	위로 스크롤: 4
	아래로 스크롤 : 5
*/
