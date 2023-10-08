/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:49:47 by seojkim           #+#    #+#             */
/*   Updated: 2023/10/08 18:13:10 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	i;

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
