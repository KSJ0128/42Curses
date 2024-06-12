/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:19:20 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/12 20:58:12 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int check_for_move(t_data *data, char c)
{
	if (data->map2D[data->Pr][data->Pc] != 'E')
		data->map2D[data->Pr][data->Pc] = '0';
	if (c == 'W' && data->map2D[data->Pr - 1][data->Pc] != '1')
		data->Pr--;
	else if (c == 'A' && data->map2D[data->Pr][data->Pc - 1] != '1')
		data->Pc--;
	else if (c == 'S' && data->map2D[data->Pr + 1][data->Pc] != '1')
		data->Pr++;
	else if (c == 'D' && data->map2D[data->Pr][data->Pc + 1] != '1')
		data->Pc++;
	else
	{
		ft_printf("이동이 불가능합니다.\n");
		return (NULL);
	}
	return (SUCCESS);
}

void collect_end_check(t_data *data, char c)
{
	data->move++;
	ft_printf("움직인 횟수 : %d\n", data->move);
	if (data->map2D[data->Pr][data->Pc] == 'C')
	{
		data->C_cnt--;
		data->map2D[data->Pr][data->Pc] = '0';
		mlx_map_to_img(*data);
	}
	else if (data->map2D[data->Pr][data->Pc] == 'E')
	{
		mlx_map_to_img(*data);
		if (data->C_cnt == 0)
			close_window(data);
	}
	else
		mlx_map_to_img(*data);
	if (data->map2D[data->Pr][data->Pc] != 'E')
		data->map2D[data->Pr][data->Pc] = 'P';
	data->img = mlx_xpm_file_to_image(data->mlx, data->player, &(data->len), &(data->len));
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->len * data->Pc, data->len * data->Pr); // 현 위치
}
