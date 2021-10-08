/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:43:10 by hugsbord          #+#    #+#             */
/*   Updated: 2021/10/08 12:35:07 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

void	msg_receipt(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR2)
		ft_putstr_fd("\n\033[92m>> message received\n\033[0m", 1);
}

int	check_error(int argc, int server_pid)
{
	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [message]\n", 1);
		return (ERROR);
	}
	if (server_pid <= 100 || server_pid >= 99998)
	{
		ft_putstr_fd("Error: invalid PID\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}

size_t	bit_sender(int pid, char c)
{
	int				bit;
	int				bin;
	static size_t	len = 0;

	bit = -1;
	while (++bit < 8)
	{
		bin = (c >> bit & 1);
		if (bin == 0)
		{
			if (kill(pid, SIGUSR1) == ERROR)
				return (ERROR);
		}
		else if (bin == 1)
		{
			if (kill(pid, SIGUSR2) == ERROR)
				return (ERROR);
		}
		usleep(150);
	}
	len++;
	return (len);
}

int	client_loop(char *msg, int server_pid)
{
	int				i;
	size_t			len;
	static size_t	total_len = 0;

	i = -1;
	len = ft_strlen(msg);
	while (msg[++i])
	{
		total_len = bit_sender(server_pid, msg[i]);
		if (total_len == ERROR)
		{
			ft_putstr_fd("PID error: Can't reach destination\n", 2);
			return (ERROR);
		}
	}
	if (len == total_len)
		bit_sender(server_pid, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	int					i;
	int					server_pid;
	struct sigaction	sa_receipt;
	sigset_t			block_mask;

	i = -1;
	if (argc == 3)
		server_pid = ft_atoi(argv[1]);
	if (check_error(argc, server_pid) == ERROR)
		exit (0);
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_receipt.sa_mask = block_mask;
	sa_receipt.sa_handler = 0;
	sa_receipt.sa_sigaction = msg_receipt;
	sa_receipt.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa_receipt, NULL);
	if (client_loop(argv[2], server_pid) == ERROR)
		exit (0);
	return (0);
}
