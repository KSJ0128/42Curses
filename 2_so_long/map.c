/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:03:13 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/01 17:28:50 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// 직사각형 형태인지, 처음과 마지막이 벽으로 둘러쌓여있는지, 세로가 벽으로 둘러쌓여있는지
int	box_check(t_game *game)
{
	int index;
	int size;

	index = 0;
	size = ft_strlen(game->map1D);
	while (index < size)
	{
		if ((index / game->width == 0) || (index / game->width == game->height - 1)) // 첫째 줄, 마지막 줄
		{
			if ((index + 1) % game->width == 0 && game->map1D[index] != '\n')
				return (NULL);
			else if ((index + 1) % game->width != 0 && game->map1D[index] != '1')
				return (NULL);
		}
		else if (index % game->width == 0 && game->map1D[index] != '1') // 중간 줄 첫 번째 인덱스
			return (NULL);
		else if ((index + 2) % game->width == 0 && game->map1D[index] != '1')  // 중간 줄 마지막 인덱스
			return (NULL);
		if ((index + 1) % game->width == 0 && game->map1D[index] != '\n')  // 매 라인 개행 체크
			return (NULL);
		index++;
	}
	return (SUCCESS);
}

// 시작, 도착, 수집품 체크
int	P_E_C_check(t_game *game)
{
	int P_pos;
	int E_pos;
	int idx;

	if (ft_strchr(game->map1D, 'P') != ft_strrchr(game->map1D, 'P') || ft_strchr(game->map1D, 'P') == NULL)
		return (NULL);
	if (ft_strchr(game->map1D, 'E') != ft_strrchr(game->map1D, 'E') || ft_strchr(game->map1D, 'E') == NULL)
		return (NULL);
	if (ft_strchr(game->map1D, 'C') == NULL)
		return (NULL);
	P_pos = ft_strchr(game->map1D, 'P') - game->map1D;
	E_pos = ft_strchr(game->map1D, 'E') - game->map1D;
	idx = 0;
	game->C_cnt = 0;
	while (game->map1D[idx] != '\0')
	{
		if (game->map1D[idx] == 'C')
			game->C_cnt++;
		idx++;
	}
	game->Pr = P_pos / game->width;
	game->Pc = P_pos % game->width;
	game->Er = E_pos / game->width;
	game->Ec = E_pos % game->width;
	return (SUCCESS);
}

int read_map(int fd, t_game *game)
{
	char	*str;
	int		index;

	index = 0;
	game->height = 0;
	game->map2D = (char **)malloc(sizeof(char *) * (word_i + 1));

	while(TRUE)
	{
		str = ft_strdup(get_next_line(fd));
		game->height++;
		if (str != NULL)
		{
			if (index == 0) // 첫 줄일 때 맵 가로 길이 설정
				game->width = ft_strlen(str);
			game->map1D = ft_strjoin(game->map1D, str);
			if (game->map1D == NULL)
				return (NULL);
			index += game->width;
		}
		if (!str) // map 다 읽었을 때
		{
			game->height--;
			free(str);
			return (SUCCESS);
		}
	}
}

int map_check(char *argv, t_game *game)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (read_map(fd, game) == NULL)
		return (NULL);
	if (!box_check(game)) // 직사각형, 박스 체크
	{
		ft_printf("Error : 직사각형 형태가 아닙니다.\n");
		return (NULL);
	}
	else if (!P_E_C_check(game))
	{
		ft_printf("Error : 출발 지점, 도착 지점, 수집품 개수가 올바르지 않습니다.\n");
		return (NULL);
	}
	game->map2D = ft_split(game->map1D, '\n');

	for (int i = 0; i < game->height; i++)
	{
		for (int j = 0; j < game->width; j++)
		{
			printf("%c",game->map2D[i][j]);
		}
		printf("\n");
	}

	if (game->map2D == NULL)
		return (NULL);
	return (SUCCESS);
}
