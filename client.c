/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:16:53 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/01/15 16:24:49 by hmokhtar         ###   ########.fr       */
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
		usleep(800);
		i--;
	}
}

void	c_msg(char *msg, int pid)
{
	int	i;

	i = 0;
	while (msg[i])
		s_bit(msg[i++], pid);
}

int	main(int ac, char **av)
{
	int		s_pid;
	char	*msg;

	if (ac != 3)
		ft_putstr("INVALID ARGUMENTS\n");
	s_pid = ft_atoi(av[1]);
	msg = av[2];
	c_msg(msg, s_pid);
	return (0);
}
