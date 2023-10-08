/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:43:18 by seojkim           #+#    #+#             */
/*   Updated: 2023/10/08 18:26:08 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char	*dest;
	const unsigned char	*source;
	int				i;

	i = 0;
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	while (n > 0)
	{
		*(dest + i) = *(source + i);
		i++;
		n--;
	}
	return (dst);
}
