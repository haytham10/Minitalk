/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:16:53 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/02/07 19:04:56 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s_bit(char str, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (str >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(600);
		i--;
	}
}

void	c_msg(char *msg, int pid)
{
	int	i;

	i = 0;
	while (msg[i])
		s_bit(msg[i++], pid);
	s_bit('\n', pid);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_putstr("INVALID PID\n");
			exit(0);
		}
		msg = av[2];
		if (!msg)
		{
			ft_putstr("INVALID MESSAGE\n");
			exit(0);
		}
		c_msg(msg, pid);
	}
	else
	{
		ft_putstr("INVALID ARGUMENTS\n");
		exit(0);
	}
	return (0);
}
