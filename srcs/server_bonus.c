/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:28:56 by hugsbord          #+#    #+#             */
/*   Updated: 2021/10/08 12:19:10 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

void	write_msg(char c, int client_pid)
{
	if (c == '\0')
	{
		kill(client_pid, SIGUSR2);
		ft_putstr_fd("\n>> ", 1);
	}
	else if (c != '\0')
		ft_putchar_fd(c, 1);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char		c = 0;
	static size_t	len = 0;
	static int		client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signal == SIGUSR1)
		signal = 0;
	else if (signal == SIGUSR2)
		signal = 1;
	c += signal << len;
	if (++len == 8)
	{
		write_msg(c, client_pid);
		client_pid = 0;
		len = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	(void)argv;
	pid = getpid();
	if (argc != 1)
		exit (0);
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_putstr_fd("Server launched:\nMy PID is: \033[92m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n\033[0m>> ", 1);
	while (42)
		pause();
	return (0);
}
