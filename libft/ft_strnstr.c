/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:43:52 by seojkim           #+#    #+#             */
/*   Updated: 2023/10/08 20:46:42 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int	n_index;
	unsigned int	h_index;

	h_index = 0;
	n_index = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h_index + n_index] != '\0' && needle[n_index] != '\0')
	{
		if (h_index + n_index >= len)
			return (0);
		else if (haystack[h_index + n_index] == needle[n_index])
			n_index++;
		else
		{
			h_index++;
			n_index = 0;
		}
	}
	if (needle[n_index] == '\0')
		return ((char *)&haystack[h_index]);
	else
		return (0);
}
