/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:36:49 by seojkim           #+#    #+#             */
/*   Updated: 2024/01/14 21:00:09 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*backup_update(char *backup, char *buff)
{
	char	*new_backup;

	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
			return (NULL);
	}
	new_backup = (char *)malloc(ft_strlen(backup) + ft_strlen(buff) + 1);
	if (!new_backup)
		return (NULL);
	ft_strlcpy(new_backup, backup, ft_strlen(backup) + 1);
	ft_strlcpy(new_backup + ft_strlen(backup), buff, ft_strlen(buff) + 1);
	free(backup);
	backup = NULL;
	return (new_backup);
}

char	*read_line(char *buff, char *backup, int r_size)
{
	buff[r_size] = '\0';
	backup = backup_update(backup, buff);
	return (backup);
}

char	*find_next_line(char *backup, char	*n_pos)
{
	char	*next_line;
	int		n_size;

	n_size = n_pos - backup + 1;
	next_line = (char *)malloc(sizeof(char) * (n_size + 1));
	if (!next_line)
		return (NULL);
	ft_strlcpy(next_line, backup, n_size + 1);
	ft_strlcpy(backup, n_pos + 1, ft_strlen(n_pos + 1) + 1);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*return_line;
	char		buff[BUFFER_SIZE + 1];
	char		*n_pos;
	ssize_t		r_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		r_size = read(fd, buff, BUFFER_SIZE);
		if (r_size < 0)
			break ;
		backup = read_line(buff, backup, r_size);
		if (!backup)
			return (NULL);
		n_pos = backup;
		while (*n_pos != '\n' && *n_pos != '\0')
			n_pos++;
		if (*n_pos == '\0' && n_pos == backup)
			break ;
		else if (*n_pos == '\0' && r_size == 0)
		{
			return_line = backup;
			backup = NULL;
			return (return_line);
		}
		else if (*n_pos == '\0' && r_size > 0)
			continue ;
		else
			return (find_next_line(backup, n_pos));
	}
	free(backup);
	backup = NULL;
	return (NULL);
}
