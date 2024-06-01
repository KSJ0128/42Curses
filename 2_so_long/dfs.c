/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:30:40 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/01 05:34:18 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int visited_setting(t_game *game)
{
	int idx;
	char *str;

	str = (char *)malloc(sizeof(game->width * game->height) + 1); // 사이즈 만큼 할당
	if (!str)
		return (NULL);
	idx = 0;
	while (game->map1D[idx] != NULL) // \n setting
	{
		if (game->map1D[idx] != '\n')
			str[idx] = game->map1D[idx];
		else
			str[idx] = '\n';
		idx++;
	}
	str[idx] = '\0'; // 마지막에 null 추가
	game->visited = ft_split(str, '\n');
	if (game->visited == NULL)
		return (NULL);
	free(str);
	return (SUCCESS);
}

void dfs(t_game *game, int now_x, int now_y)
{
    game->visited[now_x][now_y] = '1'; // current 방문
	if (now_x == game->Er && now_y == game->Ec) // 도착 지점 방문시
		return ;
	if (now_x - 1 >= 0 && game->visited[now_x - 1][now_y] == '0' && game->map2D[now_x - 1][now_y] != '1')
			dfs(game, now_x - 1, now_y);
	if (now_x + 1 < game->height && game->visited[now_x + 1][now_y] == '0' && game->map2D[now_x + 1][now_y] != '1')
			dfs(game, now_x + 1, now_y);
	if (now_y - 1 >= 0 && game->visited[now_x][now_y - 1]== '0' && game->map2D[now_x][now_y - 1] != '1')
			dfs(game, now_x, now_y - 1);
	if (now_y + 1 < game->width - 1 && game->visited[now_x][now_y + 1] == '0' && game->map2D[now_x][now_y + 1] != '1')
			dfs(game, now_x, now_y + 1);
	return ;
}

int route_check(t_game *game)
{
	if (!visited_setting(game))
		return (NULL);
    dfs(game, game->Pr, game->Pc);
    if (game->visited[game->Er][game->Ec] == '0')
    {
        ft_printf("Error : 출발 지점에서 도착 지점에 도착할 수가 없습니다.\n");
        return (NULL);
    }
    else
    {
        ft_printf("Correct Route\n");
    }
    return (SUCCESS);
}
