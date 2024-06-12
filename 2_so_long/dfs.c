/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:30:40 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/12 20:36:40 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int visited_setting(t_data *data)
{
	int	idx;

	data->visited = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (data->visited == NULL)
		return (NULL);
	idx = 0;
	while (idx < data->height)
	{
		data->visited[idx] = (char *)malloc(data->width + 1);
		if (data->visited[idx] == NULL)
		{
			free_split(data->visited, idx);
			return (NULL);
		}
		ft_memset(data->visited[idx], '0', data->width);
		data->visited[idx][data->width - 1] = '\n';
		data->visited[idx][data->width] = '\0';
		idx++;
	}
	data->visited[idx] = NULL;
	return (SUCCESS);
}

void dfs(t_data *data, int now_x, int now_y)
{
	if (now_x < 0 || now_x >= data->height || now_y < 0 || now_y >= data->width) // 범위 넘어감
		return ;
	if (data->visited[now_x][now_y] == '1') // 이미 방문한 지점
		return ;
    data->visited[now_x][now_y] = '1'; // current 방문
	if (now_x == data->Er && now_y == data->Ec) // 도착 지점 방문시
		return ;
	if (now_x - 1 >= 0 && data->visited[now_x - 1][now_y] == '0' && data->map2D[now_x - 1][now_y] != '1') // to down
		dfs(data, now_x - 1, now_y);
	if (now_x + 1 < data->height && data->visited[now_x + 1][now_y] == '0' && data->map2D[now_x + 1][now_y] != '1') // to up
		dfs(data, now_x + 1, now_y);
	if (now_y - 1 >= 0 && data->visited[now_x][now_y - 1]== '0' && data->map2D[now_x][now_y - 1] != '1') // to left
		dfs(data, now_x, now_y - 1);
	if (now_y + 1 < data->width - 1 && data->visited[now_x][now_y + 1] == '0' && data->map2D[now_x][now_y + 1] != '1') // to right
		dfs(data, now_x, now_y + 1);
	return ;
}

int route_check(t_data *data)
{
	if (!visited_setting(data))
		return (NULL);
	for(int i = 0; i < data->height; i++)
		ft_printf(data->map2D[i]);
	ft_printf("\n");
    dfs(data, data->Pr, data->Pc);
	for(int i = 0; i < data->height; i++)
		ft_printf(data->visited[i]);
    ft_printf("\n");
	if (data->visited[data->Er][data->Ec] == '0')
    {
        ft_printf("Error : 출발 지점에서 도착 지점에 도착할 수가 없습니다.\n");
        return (NULL);
    }
    else
        ft_printf("Correct Route\n");
    return (SUCCESS);
}
