/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:03:13 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/12 20:35:33 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// 직사각형 형태인지, 처음과 마지막이 벽으로 둘러쌓여있는지, 세로가 벽으로 둘러쌓여있는지
int	box_check(t_data *data)
{
	int idx;
	int size;

	idx = 0;
	data->width = ft_strlen(data->map2D[0]);
	while (idx < data->height)
	{
		size = ft_strlen(data->map2D[idx]);
		if (data->width != size) // 직사각형 체크
			return (NULL);
		if ((idx == 0) || (idx == data->height - 1)) // 첫째 줄, 마지막 줄
		{
			if (ft_strchr(data->map2D[idx], '0') != NULL || (ft_strchr(data->map2D[idx], 'C') != NULL))
				return (NULL);
			else if (ft_strchr(data->map2D[idx], 'P') != NULL || (ft_strchr(data->map2D[idx], 'E') != NULL))
				return (NULL);
		}
		else if (data->map2D[idx][0] != '1' || data->map2D[idx][size-2] != '1')
			return (NULL);
		idx++;
	}
	return (SUCCESS);
}

int find_P_E(t_data *data, char *str, char c, int r)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == c && c == 'P')
		{
			data->Pr = r;
			data->Pc = idx;
			data->P_check++;
		}
		if (str[idx] == c && c == 'E')
		{
			data->Er = r;
			data->Ec = idx;
			data->E_check++;
		}
		idx++;
	}
	return (SUCCESS);
}

int find_C(t_data *data, char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == 'C')
			data->C_cnt++;
		idx++;
	}
	return (SUCCESS);
}

// 시작, 도착, 수집품 체크
int	P_E_C_check(t_data *data)
{
	int idx;

	idx = 0;
	data->P_check = 0;
	data->E_check = 0;
	data->C_cnt = 0;
	while (idx < data->height)
	{
		if (ft_strchr(data->map2D[idx], 'P') != NULL)
			find_P_E(data, data->map2D[idx], 'P', idx);
		if (ft_strchr(data->map2D[idx], 'E') != NULL)
			find_P_E(data, data->map2D[idx], 'E', idx);
		if (ft_strchr(data->map2D[idx], 'C') != NULL)
			find_C(data, data->map2D[idx]);
		idx++;
	}
	if (data->P_check != 1 || data->E_check != 1 || data->C_cnt < 1)
		return (NULL);
	return (SUCCESS);
}

int map_check(t_data *data)
{
	if (!box_check(data)) // 직사각형, 박스 체크
	{
		ft_printf("Error : 직사각형 형태가 아닙니다.\n");
		return (NULL);
	}
	else if (!P_E_C_check(data))
	{
		ft_printf("Error : 출발 지점, 도착 지점, 수집품 개수가 올바르지 않습니다.\n");
		return (NULL);
	}
	return (SUCCESS);
}
