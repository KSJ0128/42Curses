/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:55:34 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/01 16:56:54 by seojkim          ###   ########.fr       */
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

int close_window(t_data *data)
{
	printf("key exit : x,y = %d,%d\n", data->width, data->height);
	if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    exit(0); // 정상 종료
    return (NULL);
}

int	key_press(int keycode, t_data *data)
{
    if (keycode == KEY_A)
        data->width--;
    if (keycode == KEY_D)
        data->width++;
    if (keycode == KEY_W)
        data->height++;
    if (keycode == KEY_S)
        data->height--;
    printf("key press : x,y = %d,%d\n", data->width, data->height);

    if (keycode == KEY_ESC)
		close_window(data);
	return (SUCCESS);
}

void mlx_initialize(t_data *data)
{
	data->width = 0;
    data->height = 0;
    data->mlx = NULL;
    data->win = NULL;
    data->img = NULL;
    data->goal = "img/goal.png";
	data->floor = "img/floor.png";
	data->item = "img/item.png";
	data->player = "img/player.png";
	data->wall = "img/wall.png";
	data->move = 0;
	data->len = 50;
}

void mlx_map_to_img(t_game *game, t_data data)
{
	int w;
	int h;

	w = 0;
	h = 0;
	while (h < game->height)
	{
		data.img = mlx_png_file_to_image(data.mlx, data.floor, &data.len, &data.len);
		mlx_put_image_to_window(data.mlx, data.win, data.img, data.len * w, data.len * h);
		if (game->map2D[h][w] == '1')
			data.img = mlx_png_file_to_image(data.mlx, data.wall, &data.len, &data.len);
		else if (game->map2D[h][w] == 'P')
			data.img = mlx_png_file_to_image(data.mlx, data.player, &data.len, &data.len);
		else if (game->map2D[h][w] == 'C')
			data.img = mlx_png_file_to_image(data.mlx, data.item, &data.len, &data.len);
		else if (game->map2D[h][w] == 'E')
			data.img = mlx_png_file_to_image(data.mlx, data.goal, &data.len, &data.len);
		mlx_put_image_to_window(data.mlx, data.win, data.img, data.len * w, data.len * h);

		if (w < game->width)
			w++;
		else
		{
			w = 0;
			h++;
		}
	}
	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			printf("%c", game->map2D[h][w]);
			++w;
		}
		h++;
		printf("\n");
	}

}

int mlx_map_display(t_game *game)
{
	t_data data;

	mlx_initialize(&data);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (NULL);
    data.win = mlx_new_window(data.mlx, game->width * 50, game->height * 50, "so_long");
	if (data.win == NULL)
		return (NULL);
	printf("Floor image path: %s\n", data.floor);
	mlx_map_to_img(game, data);
	mlx_key_hook(data.win, key_press, &data); // 키 훅 함수 등록 (키 누름 이벤트)
	mlx_hook(data.win, X_EVENT_KEY_EXIT, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (SUCCESS);
}

	// mlx = mlx_init(); // 그래픽 시스템에 대한 연결 설정, MLX 위치를 리턴
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); // MLX를 디스플레이 할 창 생성
	// // mlx_loop(mlx); // 렌더링 -> 기본 창
	//
	// // img = mlx_new_image(mlx, 1920, 1080); // 창에 이미지를 초기화
	// img.img = mlx_new_image(mlx, 1920, 1080); // 픽셀에 따라 바이트 조절 위해
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian); // 포인터로 전달
	//
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); // (5,5)에 빨간색 픽셀 색칠
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); // 창에 배치
	//
	// mlx_loop(mlx);
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	//
	// mlx_hook(vars.win, 2, 1L<<0, window_close, &vars); // 사용 예시
	// mlx_key_hook(vars.win, key_hook, &vars); // 키보드 후킹
	// mlx_mouse_hook(vars.win, mouse_hook, &vars); // 마우스 후킹, 특정 코드 대상으로 어떻게 ?

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

	// img.img = mlx_png_file_to_image(img.mlx, img.floor, &img.width, &img.height);
	// mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	//
	// img.img = mlx_png_file_to_image(img.mlx, img.goal, &img.width, &img.height);
	// mlx_put_image_to_window(img.mlx, img.win, img.img, 50, 50);
	//
	// img.img = mlx_png_file_to_image(img.mlx, img.item, &img.width, &img.height);
	// mlx_put_image_to_window(img.mlx, img.win, img.img, 100, 100);
	//
	// img.img = mlx_png_file_to_image(img.mlx, img.player, &img.width, &img.height);
	// mlx_put_image_to_window(img.mlx, img.win, img.img, 150, 150);
	//
	// img.img = mlx_png_file_to_image(img.mlx, img.wall, &img.width, &img.height);
	// mlx_put_image_to_window(img.mlx, img.win, img.img, 200, 200);
	//
	// mlx_hook(img.win, 17, 0, window_close, &img);
	// mlx_loop(img.mlx);
