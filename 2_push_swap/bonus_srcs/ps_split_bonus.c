/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:23:58 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/15 15:49:03 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_strdup_size(char *src, int size)
{
	char	*dup;

	dup = (char *)malloc(size + 1);
	if (!dup)
		exit(1);
	ft_strlcpy(dup, src, size + 1);
	return (dup);
}

void	ps_free_split(char **split, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ;
}

long long	ps_word_count(char *str, char c)
{
	long long	i;
	long long	cnt;
	int			sep;

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

int	ps_insert_word(char **split, char *str, char c)
{
	long long	word_len;
	int			k;

	word_len = 0;
	k = 0;
	while (str[word_len] != '\0')
	{
		while (str[word_len] != c && str[word_len] != '\0')
			word_len++;
		if (word_len != 0)
		{
			split[k] = ps_strdup_size(str, word_len);
			if (split[k] == 0)
			{
				ps_free_split(split, k);
				return (0);
			}
			k++;
		}
		if (str[word_len] == '\0')
			break ;
		str += word_len + 1;
		word_len = 0;
	}
	return (1);
}

char	**ps_split(char *str, char c, long long *stack_size)
{
	char	**split;

	*stack_size = ps_word_count(str, c);
	split = (char **)malloc(sizeof(char *) * (*stack_size + 1));
	if (!split)
		exit(1);
	if (!ps_insert_word(split, str, c))
		exit(1);
	else
	{
		split[*stack_size] = 0;
		return (split);
	}
}
