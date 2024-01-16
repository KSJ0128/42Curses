/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:36:49 by seojkim           #+#    #+#             */
/*   Updated: 2024/01/16 10:35:17 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_next_line(char **backup, char	*n_pos)
{
	char	*next_line;
	int		n_size;

	n_size = n_pos - *backup + 1;
	next_line = (char *)malloc(sizeof(char) * (n_size + 1));
	if (!next_line)
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	ft_strlcpy(next_line, *backup, n_size + 1);
	ft_strlcpy(*backup, n_pos + 1, ft_strlen(n_pos + 1) + 1);
	return (next_line);
}

int	backup_update(char **backup, char *buff)
{
	char	*new_backup;

	if (!*backup)
	{
		*backup = ft_strdup("");
		if (!*backup)
			return (0);
	}
	new_backup = (char *)malloc(ft_strlen(*backup) + ft_strlen(buff) + 1);
	if (!new_backup)
	{
		free(*backup);
		*backup = NULL;
		return (0);
	}
	ft_strlcpy(new_backup, *backup, ft_strlen(*backup) + 1);
	ft_strlcpy(new_backup + ft_strlen(*backup), buff, ft_strlen(buff) + 1);
	free(*backup);
	*backup = new_backup;
	return (1);
}

int	read_line(int fd, char *buff, char **backup)
{
	int	r_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	r_size = read(fd, buff, BUFFER_SIZE);
	if (r_size < 0)
		return (-1);
	if (r_size == 0 && *backup == NULL)
		return (0);
	if (r_size == 0 && ft_strlen(*backup) == 0)
		return (-1);
	buff[r_size] = '\0';
	if (backup_update(backup, buff) == 0)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buff[BUFFER_SIZE + 1];
	char		*return_line;
	int			check;

	while (1)
	{
		check = read_line(fd, buff, &backup);
		if (check == 0)
			return (NULL);
		else if (check == -1)
			break ;
		if (ft_strchr(backup, '\n') != NULL)
			return (find_next_line(&backup, ft_strchr(backup, '\n')));
		else if (ft_strlen(buff) == 0)
		{
			return_line = backup;
			backup = NULL;
			return (return_line);
		}
	}
	free(backup);
	backup = NULL;
	return (NULL);
}
