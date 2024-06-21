/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 02:05:22 by seojkim           #+#    #+#             */
/*   Updated: 2024/06/18 15:44:31 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_exception(int err)
{
	if (err == 0)
		ft_printf("Error\nInvalid file count.\n");
	else if (err == 1)
		ft_printf("Error\nInvalid file name.\n");
	else if (err == 2)
		ft_printf("Error\nIt's not a rectangle.\n");
	else if (err == 3)
		ft_printf("Error\nIt's invalid P, E, C.\n");
	exit(1);
}

void	free_split(char **split, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	set_height(char **argv, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	game->height = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			game->height++;
			free(line);
		}
		else
			break ;
	}
	close(fd);
}

int	read_map(t_game *game, char **argv)
{
	int	idx;
	int	fd;

	set_height(argv, game);
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (game->map == NULL)
		return (0);
	idx = 0;
	fd = open(argv[1], O_RDONLY);
	while (idx < game->height)
	{
		game->map[idx] = get_next_line(fd);
		if (game->map[idx] == NULL)
		{
			free_split(game->map, idx);
			free(game);
			return (0);
		}
		idx++;
	}
	game->map[idx] = "\0";
	close(fd);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		handle_exception(0);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		handle_exception(1);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		free_split(game->map, game->height);
		free(game);
		return (0);
	}
	if (!read_map(game, argv))
		return (0);
	if (!check_valid_map(game) || !check_valid_pec(game) || !route_check(game))
	{
		free_split(game->map, game->height);
		free(game);
		return (0);
	}
	if (!mlx_map_display(game))
		return (0);
	return (SUCCESS);
}
