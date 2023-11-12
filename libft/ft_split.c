/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:17:03 by seojkim           #+#    #+#             */
/*   Updated: 2023/11/12 00:42:39 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup2(char *src, int size)
{
	char	*dup;

	dup = (char *)malloc(size + 1);
	if (dup == NULL)
		return (0);
	ft_strlcpy(dup, src, size + 1);
	return (dup);
}

void	insert_word(char **split, char *str, char c)
{
	int	word_len;
	int	i;
	int	k;

	word_len = 0;
	i = 0;
	k = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[word_len] == c || str[word_len] == '\0')
		{
			if (word_len != 0)
				split[k++] = ft_strdup2(str, word_len);
			str += word_len + 1;
			word_len = 0;
		}
		else
			word_len++;
	}

}

int	word_count(char *str, char c)
{
	int	i;
	int	cnt;
	int	sep;

	i = 0;
	cnt = 0;
	sep = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			sep = 0;
		else if (str[i] != c)
		{
			if (sep == 0)
				cnt++;
			sep = 1;
		}
		i++;
	}
	return (cnt);
}

char	**ft_split(char *str, char c)
{
	char	**split;
	int		word_i;

	word_i = word_count(str, c);
	split = (char **)malloc(sizeof(char *) * (word_i + 1));
	if (split == NULL)
		return (0);
	insert_word(split, str, c);
	split[word_i] = 0;
	return (split);
}
