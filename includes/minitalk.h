/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:29:41 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/29 11:22:11 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h> 

typedef struct s_msg
{
	char		c;
	size_t		len;
}				t_msg;

# define SUCCESS 0
# define ERROR -1

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putchar_fd(int c, int fd);
void	ft_putnbr_fd(int nb, int fd);
int		ft_atoi(const char *str);

#endif
