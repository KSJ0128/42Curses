/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:30:40 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/17 21:29:41 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	visited_setting(t_game *game)
{
	int	idx;

	game->visited = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (game->visited == NULL)
		return (0);
	idx = 0;
	while (idx < game->height)
	{
		game->visited[idx] = (char *)malloc(game->width + 1);
		if (game->visited[idx] == NULL)
		{
			free_split(game->visited, idx);
			return (0);
		}
		ft_memset(game->visited[idx], '0', game->width);
		game->visited[idx][game->width] = '\0';
		idx++;
	}
	game->visited[idx] = NULL;
	return (SUCCESS);
}

void	dfs(t_game *game, int now_r, int now_c, int *check_c)
{
	if (now_r < 0 || now_r >= game->height)
		return ;
	else if (now_c < 0 || now_c >= game->width)
		return ;
	if (game->visited[now_r][now_c] == '1')
		return ;
	game->visited[now_r][now_c] = '1';
	if (now_r == game->er && now_c == game->ec)
		return ;
	else if (game->map[now_r][now_c] == 'C')
		(*check_c)--;
	if (game->map[now_r - 1][now_c] != '1')
		dfs(game, now_r - 1, now_c, check_c);
	if (game->map[now_r + 1][now_c] != '1')
		dfs(game, now_r + 1, now_c, check_c);
	if (game->map[now_r][now_c - 1] != '1')
		dfs(game, now_r, now_c - 1, check_c);
	if (game->map[now_r][now_c + 1] != '1')
		dfs(game, now_r, now_c + 1, check_c);
	return ;
}

int	route_check(t_game *game)
{
	int	check_c;

	if (!visited_setting(game))
		return (0);
	check_c = game->c_cnt;
	dfs(game, game->pr, game->pc, &check_c);
	if (game->visited[game->er][game->ec] == '0' || check_c != 0)
	{
		ft_printf("Error : It's invalid route.\n");
		return (0);
	}
	return (SUCCESS);
}
