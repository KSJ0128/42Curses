/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:51:48 by seojkim           #+#    #+#             */
/*   Updated: 2024/05/27 23:55:42 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*u_s1;
	const unsigned char	*u_s2;
	int					i;

	u_s1 = (const unsigned char *)s1;
	u_s2 = (const unsigned char *)s2;
	i = 0;
	while ((u_s1[i] || u_s2[i]) && n)
	{
		if (u_s1[i] > u_s2[i])
			return (1);
		else if (u_s1[i] < u_s2[i])
			return (-1);
		i++;
		n--;
	}
	return (0);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	i;

	if (!src)
		return (ft_strlen(dest));
	d_len = ft_strlen(dest);
	s_len = ft_strlen((char *)src);
	i = 0;
	while (src[i] != '\0' && d_len + i + 1 < size)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	if (d_len > size)
		return (s_len + size);
	else
		return (s_len + d_len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char			*trim;
	unsigned int	f;
	unsigned int	b;

	if (s1[0] == '\0' || set[0] == '\0')
		return (ft_strdup(s1));
	f = 0;
	b = ft_strlen(s1);
	while (ft_strchr(set, s1[f]) != 0 && s1[f] != '\0')
		f++;
	while (ft_strchr(set, s1[b - 1]) != 0 && b > f)
		b--;
	trim = (char *)malloc(b - f + 1);
	if (trim == NULL)
		return (0);
	ft_strlcpy(trim, s1 + f, b - f + 1);
	return (trim);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len > 0)
	{
		*ptr = c;
		ptr++;
		len--;
	}
	return (b);
}


