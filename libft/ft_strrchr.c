/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:09:12 by seojkim           #+#    #+#             */
/*   Updated: 2023/10/08 17:06:39 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_len(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		index++;
	}
	return (index);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_len(s) - 1;
	while (i >= 0)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	return (0);
}
