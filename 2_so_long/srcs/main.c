/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 02:05:22 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/12 22:43:25 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_split(char **split, int k)
{
	int i;

	i = 0;
	while (i < k)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// void free_game_resources(t_game *game)
// {
//     if (game->map2D)
//     {
//         for (int i = 0; game->map2D[i]; i++)
//             free(game->map2D[i]);
//         free(game->map2D);
//     }
// 	if (game->visited)
// 	{
// 		for (int i = 0; game->visited[i]; i++)
// 			free(game->visited[i]);
// 		free(game->visited);
// 	}
// 	if (game)
// 		free(game);
// }

void count_line(int fd, t_data *data)
{
	data->height = 0;
	while (TRUE)
	{
		if (get_next_line(fd) != NULL)
			data->height++;
		else
			break;
	}
}
// map -> 2차원 배열
int map_setting(t_data *data, char **argv, int fd)
{
	int idx;

	count_line(fd, data);
	fd = open(argv[1], O_RDONLY);
	data->map2D = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (data->map2D == NULL)
		return (NULL);
	idx = 0;
	while (idx < data->height)
	{
		data->map2D[idx] = ft_strdup(get_next_line(fd));
		if (data->map2D[idx] == NULL)
		{
			free_split(data->map2D, idx);
			free(data);
			return (NULL);
		}
		idx++;
	}
	data->map2D[idx] = "\0";
	return (SUCCESS);
}

int main(int argc, char *argv[])
{
	t_data *data;
	int fd;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	if (argc < 2)
		return (NULL);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (map_setting(data, argv, fd) == NULL)
		return (NULL);
	close(fd);
	if (!map_check(data) || !route_check(data))
	{
		free_split(data->map2D, data->height);
		free_split(data->visited, data->height);
		return (NULL);
	}
	mlx_map_display(data);
	return (0);
}
