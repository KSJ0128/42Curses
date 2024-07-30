/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojkim <seojkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:23:47 by seojkim           #+#    #+#             */
/*   Updated: 2024/07/30 14:25:13 by seojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void print_signal(char tmp, int *pid_status)
{
	if (tmp == '\n')
		*pid_status = 1;
	ft_putchar_fd(tmp, 1);
}

void get_signal(int sig, struct __siginfo *info, void *any)
{
	static int bit;
	static char	tmp;

	(void) any;
	if (sig == SIGUSR2)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (tmp == '\0')
		{
			ft_printf("Done!\n");
			kill(info->si_pid, SIGUSR1);
		}
		ft_putchar_fd(tmp, 1);
		bit = 0;
		tmp = 0;
	}
}

int main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO; // sa_flags를 설정해야 siginfo_t를 사용할 수 있음
	sa.__sigaction_u.__sa_sigaction = get_signal; // signal handler
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_printf("Server's pid : %d\n", getpid());
	while(1)
		pause();
}
