/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:43:10 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/29 11:45:30 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

void	bit_sender(int i, int pid, int mask, char *msg)
{
	if ((msg[i] & mask) == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("PID error: Can't reach destination\n", 2);
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("PID error: Can't reach destination\n", 2);
			exit(0);
		}
	}
}

void	ascii_to_bin(int pid, char *msg, int len)
{
	int		i;
	int		mask;

	i = 0;
	while (i <= len)
	{
		mask = 128;
		if (i == len)
			msg[i] = '\n';
		while (mask > 0)
		{
			bit_sender(i, pid, mask, msg);
			mask >>= 1;
			usleep(75);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		msg;

	pid = 0;
	msg = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [message]\n", 1);
		exit (0);
	}
	pid = ft_atoi(argv[1]);
	ascii_to_bin(pid, argv[2], ft_strlen(argv[2]));
	return (0);
}
