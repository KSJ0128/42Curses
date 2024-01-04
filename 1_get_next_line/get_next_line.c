/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:36:49 by seojkim           #+#    #+#             */
/*   Updated: 2024/01/04 20:50:30 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_line(char *backup, char *next_pos)
{
	char	*return_str;
	size_t	next_line;

	next_line = next_pos - backup;
	return_str = (char *)malloc(sizeof(char) * (next_line) + 2);
	if (return_str == NULL)
		return (NULL);
	ft_strlcpy(return_str, backup, next_line + 2);
	ft_strlcpy(backup, next_pos + 1, ft_strlen(next_pos + 1) + 2);
	return (return_str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*temp;
	static char	*backup;
	ssize_t		bytes_read;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		if (backup == NULL)
			backup = ft_strjoin("", buff);
		else
		{
			temp = backup;
			backup = ft_strjoin(backup, buff);
			free(temp);
		}
		if (ft_strchr(backup, '\n') != NULL)
		{
			free(buff);
			return (return_line(backup, ft_strchr(backup, '\n')));
		}
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (backup != NULL)
		return (return_line(backup, ft_strchr(backup, '\0')));
	return (NULL);
}
