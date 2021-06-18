/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:40:11 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/18 20:36:19 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

void	send_message(char *msg)
{

}
void	char_to_bin(int c)
{
	int		bin;
	int		i;
	int		j;
	int		tab[10];

	bin = 0;
	i = 0;
	while (c > 0)
	{
		tab[i] = c % 2;
		c = c / 2;
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		ft_putnbr_fd(tab[i], 1);
		i--;
	}
	ft_putstr_fd("\n", 1);
}

void	signal_handler(int num)
{
	
}

int		main(int argc, char **argv)
{
	int		pid;
	char	*msg;
	int i = 0;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [message]\n", 1);
		exit (0);
	}
	
	signal(SIGUSR1, signal_handler);
	while (argv[2][i])
	{
		ft_putchar_fd(argv[2][i],1);
//		ft_putnbr_fd(argv[2][i],1);
		char_to_bin(argv[2][i]);
		i++;
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR2, signal_handler);
	return (0);
}
