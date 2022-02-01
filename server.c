/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:23:18 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/01/11 18:23:18 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data m_data;

void	rst(void)
{
	m_data.i = 0;
	m_data.c = 0;
	m_data.c_pid = 0;
}

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	signum -= SIGUSR1;
	if (m_data.c_pid != info->si_pid)
		rst();
	m_data.c = m_data.c << 1 | signum;
	m_data.i++;
	if (m_data.i == 8)
	{
		write(1, &m_data.c, 1);
		rst();
	}
	m_data.c_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			b_mask;

	rst();
	printf("PID: %d\n", getpid());
	sigemptyset(&b_mask);
	sigaddset(&b_mask, SIGUSR1);
	sigaddset(&b_mask, SIGUSR2);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = b_mask;
	sa_signal.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (1)
		sleep(1);
}