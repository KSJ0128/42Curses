/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:50:37 by seojkim           #+#    #+#             */
/*   Updated: 2023/12/27 15:38:31 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		print_args(char c, va_list *args, int *cnt);
int		print_args2(char c, va_list *args, int *cnt);
int		print_char(char c, int *cnt);
int		print_str(char *s, int *cnt);
int		print_nbr(long long n, char *dec, int *cnt);
int		print_str_hex(unsigned int n, int hex_check, int *cnt);
int		print_addr(void *h_addr, char *hex, int *cnt);
#endif
