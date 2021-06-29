/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:28:56 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/29 11:31:14 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

static t_msg	g_msg;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_msg.c = g_msg.c << 1;
	else if (signal == SIGUSR2)
	{
		g_msg.c = g_msg.c << 1;
		g_msg.c += 1;
	}
	if (g_msg.len == 7)
	{
		ft_putchar_fd(g_msg.c, 1);
		g_msg.c = 0;
		g_msg.len = -1;
	}
	g_msg.len++;
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_putstr_fd("Server launched:\nMy PID is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	g_msg.len = 0;
	g_msg.c = 0;
	while (42)
	{
		if (signal(SIGUSR1, signal_handler) == SIG_ERR)
			exit(0);
		if (signal(SIGUSR2, signal_handler) == SIG_ERR)
			exit(0);
	}
	return (0);
}
