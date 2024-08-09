/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:54:15 by seojkim           #+#    #+#             */
/*   Updated: 2024/08/04 14:23:22 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signal(int pid, char byte)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (byte & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(100);
		usleep(100);
	}
}

void	set_signal(int pid, char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		send_signal(pid, str[idx]);
		idx++;
	}
	send_signal(pid, '\n');
	send_signal(pid, '\0');
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	if (pid > 327268 || pid < 0)
		exit(0);
	set_signal(pid, argv[2]);
}
