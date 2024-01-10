/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:34:28 by seojkim           #+#    #+#             */
/*   Updated: 2024/01/09 21:45:04 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

size_t 	ft_strlen(const char *s);
char 	*ft_strchr(const char *s, int c);
size_t 	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s1);
char 	*ft_strjoin(const char *s1, const char *s2);
char 	*get_next_line(int fd);
#endif
