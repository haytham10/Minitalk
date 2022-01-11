/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:36:28 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/01/11 17:36:28 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *str)
{
	if (str)
		free(str);
	printf("CLIENT: UNEXPECTED ERROR.\n");
	exit(EXIT_FAILURE);
}

int	s_null(int s_pid, char *msg)
{
	static int i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			error(msg);
		return (0);
	}
	return (1);
}

int	s_bit(int pid, char *str)
{
	static char	*msg = 0;
	static int	s_pid = 0;
	static int	bits = -1;

	if (str)
		msg = ft_strdup(str);
	if (!msg)
		error(0);
	if (pid)
		s_pid = pid;
	if (msg[++bits / 8])
	{
		if (msg[bits / 8] & (0x80 >> (bits % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				error (msg);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			error(msg);
		return (0);
	}
	if (!s_null(s_pid, msg))
		return (0);
	free(msg);
	return (1);
}

void	handler(int signum)
{
	int	i;

	i = 0;
	if (signum == SIGUSR1)
		i = s_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		printf("CLIENT: SERVER ENDED UNEXPECTEDLY!.\n");
		exit(EXIT_FAILURE);
	}
	if (i)
	{
		printf("OPERATION SUCCESSFUL.\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3 || !ft_isdigit(av[1]))
		printf("INVALID ARGUMENTS.\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	s_bit(ft_atoi(av[1]), av[2]);
	while (1)
		pause();

}