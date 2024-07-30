/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:23:51 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/28 00:31:43 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void send_signal(int pid, char byte)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if (byte & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(100);
	}
}

void set_signal(int pid, char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		send_signal(pid, str[idx]);
		idx++;
	}
	send_signal(pid, '\n');
	send_signal(pid, '\0');
}

void get_done(int sig)
{
	if (sig == SIGUSR1)
		exit(0);
}

int main(int argc, char *argv[])
{
	int pid;

	if (argc != 3)
		exit(0);
	signal(SIGUSR1, get_done);
	pid = ft_atoi(argv[1]); // server pid
	if (pid > 327268 || pid < 0)
		exit(0);
	set_signal(pid, argv[2]);
	while(1)
		pause();
}
