/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:47:55 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/01/11 17:47:55 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINITALK_H
#define MINITALK_H

typedef struct	s_data{
		int		i;
		char	c;
		int		c_pid;
}	t_data;

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int		ft_atoi(const char	*str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(int c);
void	c_msg(char *msg, int pid);
void	s_bit(char	str, int pid);
void	handler(int signum, siginfo_t *info, void *context);
void	rst(void);
#endif