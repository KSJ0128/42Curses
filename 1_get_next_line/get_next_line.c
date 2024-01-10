/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:36:49 by seojkim           #+#    #+#             */
/*   Updated: 2024/01/10 21:32:05 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*backup_update(char *backup, char *buff)
{
	char	*new_backup;

	if (!backup)
		backup = ft_strdup("");
	new_backup = (char *)malloc(ft_strlen(backup) + ft_strlen(buff) + 1);
	if (!new_backup)
		return (NULL);
	ft_strlcpy(new_backup, backup, ft_strlen(backup) + 1);
	ft_strlcpy(new_backup + ft_strlen(backup), buff, ft_strlen(buff) + 1);
	free(backup);
	backup = NULL;
	return (new_backup);
}

char	*find_next_line(char *backup)
{
	char	*next_line;
	char	*n_pos;
	int		n_size;

	n_pos = backup;
	while (*n_pos != '\n' && *n_pos != '\0')
		n_pos++;
	if (*n_pos == '\0')
		return (NULL);
	else
	{
		n_size = n_pos - backup;
		next_line = (char *)malloc(sizeof(char) * (n_size + 2)); // 개행 위치 + null
		if (!next_line)
			return (NULL);
		ft_strlcpy(next_line, backup, n_size + 2);
		ft_strlcpy(backup, n_pos + 1, ft_strlen(n_pos + 1) + 1);
		return (next_line);
	}
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buff;
	char		*return_line;
	ssize_t		r_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while ((r_size = read(fd, buff, BUFFER_SIZE)) >= 0)
	{
		buff[r_size] = '\0';
		if (r_size == 0)
		{
			free(buff);
			buff = NULL;
			if (!backup)
				return (NULL);
			return_line = find_next_line(backup);
			if (!return_line)
			{
				free(return_line);
				return_line = (char *)malloc(ft_strlen(backup) + 1);
				if (!return_line)
					return (NULL);
				ft_strlcpy(return_line, backup, ft_strlen(backup) + 1);
				free(backup);
				backup = NULL;
			}
			return (return_line);
		}
		else
		{
			backup = backup_update(backup, buff);
			return_line = find_next_line(backup);
			if (!return_line)
			{
				free(return_line);
				continue;
			}
			else
			{
				free(backup);
				free(buff);
				backup = NULL;
				buff = NULL;
				return (return_line);
			}
		}
	}
	free(buff);
	buff = NULL;
	return (NULL);
}