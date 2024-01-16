/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:36:51 by seojkim           #+#    #+#             */
/*   Updated: 2024/01/16 16:16:22 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

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
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;

	if (src == NULL || dest == NULL)
		return (0);
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

char	*ft_strdup(const char *s1)
{
	char	*address;

	if (s1 == NULL)
		return (NULL);
	address = (char *)malloc((ft_strlen(s1) + 1));
	if (!address)
		return (NULL);
	ft_strlcpy(address, s1, ft_strlen(s1) + 1);
	return (address);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*join;
	unsigned int	s1_index;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	s1_index = ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcpy(join + s1_index, s2, ft_strlen(s2) + 1);
	return (join);
}
