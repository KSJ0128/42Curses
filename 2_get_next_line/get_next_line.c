/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:36:49 by seojkim           #+#    #+#             */
/*   Updated: 2023/12/30 18:56:58 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (0);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (size > 1 && src[i] != '\0')
	{
		*(dest + i) = *(src + i);
		size--;
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

char *return_line(static char *backup) // return 완성, backup setting
{
	char *return_lines;

	return_lines = backup;
	return_lines[ft_strchr(backup, '\n') + 1] = '\0';
	backup = ft_strchr(backup, '\n') + 1;
	return (return_lines);
}

char	*get_next_line(int fd)
{
	void *buf;
	static char *backup;

	backup = "";
	while (true)
	{
		if (read(fd, buf, BUFFER_SIZE) <= 0)
			return (NULL);
		backup += (char *) buf;
		if (ft_strchr(backup, '\n') != 0)
			return (return_line);
	}
}

