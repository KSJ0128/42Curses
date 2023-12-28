/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:50:04 by seojkim           #+#    #+#             */
/*   Updated: 2023/12/28 16:12:03 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_args(char c, va_list *args, int *cnt)
{
	if (c == 'c')
	{
		if (print_char((char)va_arg(*args, int), cnt) == -1)
			return (-1);
	}
	else if (c == 'i' || c == 'd')
	{
		if (print_nbr(va_arg(*args, int), "0123456789", cnt) == -1)
			return (-1);
	}
	else if (c == 'u')
	{
		if (print_nbr(va_arg(*args, unsigned int), "0123456789", cnt) == -1)
			return (-1);
	}
	else
	{
		if (print_args2(c, args, cnt) == -1)
			return (-1);
	}
	return (0);
}

int	print_args2(char c, va_list *args, int *cnt)
{
	if (c == 'x')
	{
		if (print_str_hex(va_arg(*args, unsigned int), 0, cnt) == -1)
			return (-1);
	}
	else if (c == 'X')
	{
		if (print_str_hex(va_arg(*args, unsigned int), 1, cnt) == -1)
			return (-1);
	}
	else if (c == 'p')
	{
		if (print_addr(va_arg(*args, void *), "0123456789abcdef", cnt) == -1)
			return (-1);
	}
	else if (c == 's')
	{
		if (print_str(va_arg(*args, char *), cnt) == -1)
			return (-1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		cnt;

	va_start(args, str);
	cnt = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(++str) == '%')
			{
				if (write(1, "%", 1) == -1)
					return (-1);
				cnt++;
			}
			else
				if (print_args(*str, &args, &cnt) == -1)
					return (-1);
		}
		else
			if (print_char(*str, &cnt) == -1)
				return (-1);
		str++;
	}
	return (cnt);
}
