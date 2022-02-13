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

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_data{
	int		i;
	char	c;
}	t_data;

int		ft_atoi(const char	*str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(int c);

#endif