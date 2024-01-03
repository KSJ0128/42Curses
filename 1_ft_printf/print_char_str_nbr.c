/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:19:08 by seojkim           #+#    #+#             */
/*   Updated: 2023/12/28 16:11:44 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, int *cnt)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*cnt)++;
	return (0);
}

int	print_str(char *s, int *cnt)
{
	int	i;

	if (s == 0)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*cnt += 6;
		return (0);
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (print_char(s[i], cnt) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	print_nbr(long long n, char *dec, int *cnt)
{
	char	num[11];
	int		i;

	if (n == 0 && print_char('0', cnt) == -1)
		return (-1);
	else
	{
		if (n < 0)
		{
			n *= -1;
			if (print_char('-', cnt) == -1)
				return (-1);
		}
		num[10] = '\0';
		i = 9;
		while (n > 0)
		{
			num[i--] = dec[n % 10];
			n /= 10;
		}
		if (print_str(&num[i + 1], cnt) == -1)
			return (-1);
	}
	return (0);
}

int	print_str_hex(unsigned int n, int hex_check, int *cnt)
{
	char	*hex;

	if (hex_check == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		if (print_str_hex(n / 16, hex_check, cnt))
			return (-1);
		if (print_char(hex[n % 16], cnt) == -1)
			return (-1);
	}
	else
	{
		if (print_char(hex[n], cnt) == -1)
			return (-1);
	}
	return (0);
}

int	print_addr(void *addr, char *hex, int *cnt)
{
	unsigned long long	h_addr;

	h_addr = (unsigned long long)addr;
	if (h_addr >= 16)
	{
		if (print_addr((void *)(h_addr / 16), hex, cnt))
			return (-1);
		if (print_char(hex[h_addr % 16], cnt) == -1)
			return (-1);
	}
	else
	{
		if (print_str("0x", cnt) == -1)
			return (-1);
		if (print_char(hex[h_addr], cnt) == -1)
			return (-1);
	}
	return (0);
}
