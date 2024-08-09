/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:54:14 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/04 14:04:03 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	get_signal(int sig)
{
	static int	bit;
	static char	tmp;

	if (sig == SIGUSR2)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(tmp, 1);
		bit = 0;
		tmp = 0;
	}
}

int	main(void)
{
	ft_printf("Server's pid : %d\n", getpid());
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while (1)
		pause();
}
