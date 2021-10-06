/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:43:10 by hugsbord          #+#    #+#             */
/*   Updated: 2021/10/06 13:57:55 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

void	msg_receipt(int signal, siginfo_t *info, void *context)
{
	(void)signal;
	(void)info;
	(void)context;
	ft_putstr_fd(">> message received\n", 1);
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

static size_t	bit_sender(int pid, char c)
{
	static size_t	len = 0;
	int				bit;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit & 1) == 0)
		{
			if (kill(pid, SIGUSR1) == ERROR)
				return (ERROR);
		}
		else if ((c >> bit & 1) == 1)
		{
			if (kill(pid, SIGUSR2) == ERROR)
				return (ERROR);
		}
		usleep(175);
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
	struct sigaction	sa_signal;

	i = -1;
	if (argc == 3)
		server_pid = ft_atoi(argv[1]);
	if (check_error(argc, server_pid) == ERROR)
		exit (0);
	sa_signal.sa_sigaction = &msg_receipt;
	sa_signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_signal, NULL);
	if (client_loop(argv[2], server_pid) == ERROR)
		exit (0);
	return (0);
}
