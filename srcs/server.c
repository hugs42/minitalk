/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:28:56 by hugsbord          #+#    #+#             */
/*   Updated: 2021/10/08 12:12:42 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

void	write_msg(char c)
{
	if (c == 0)
		ft_putstr_fd("\n>> ", 1);
	else if (c != '\0')
		ft_putchar_fd(c, 1);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char		c = 0;
	static size_t	len = 0;

	(void)context;
	if (signal == SIGUSR1)
		signal = 0;
	else if (signal == SIGUSR2)
		signal = 1;
	c += signal << len;
	if (++len == 8)
	{
		write_msg(c);
		c = 0;
		len = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	if (argc != 1)
		exit (0);
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	pid = getpid();
	ft_putstr_fd("Server launched:\nMy PID is: \033[92m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n\033[0m>> ", 1);
	while (42)
		pause();
	return (0);
}
