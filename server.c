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

t_data	g_data;

void	rst(void)
{
	g_data.i = 0;
	g_data.c = 0;
	g_data.c_pid = 0;
}

void	handler(int signum, siginfo_t *info, void *context)
{
	
	(void)context;
	if (g_data.c_pid != info->si_pid)
		rst();
	signum -= SIGUSR1;
	g_data.c = g_data.c << 1 | signum;
	g_data.i++;
	if (g_data.i == 8)
	{
		ft_putchar(g_data.c);
		rst();
	}
	g_data.c_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa_signal;

	rst();
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (1)
		sleep(1);
	return (0);
}
