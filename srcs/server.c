/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:28:56 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/18 22:11:10 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

int		bin_to_dec(int bin)
{
	int		num;
	int		dec;
	int		base;
	int		rem;

	num = bin;
	dec = 0;
	base = 1;
	rem = 0;
	while (num > 0)
	{
		rem = num % 10;
		dec = dec + rem * base; 
		num = num / 10;
		base = base * 2;
	}
	ft_putnbr_fd(dec, 1);
	return (dec);
}

void	signal_handler(int num)
{
	
}

int		main(void)
{
	int		pid;
	char	*show_pid;

	pid = getpid();
	show_pid = ft_itoa(pid);
	ft_putstr_fd(show_pid, 1);
	ft_putchar_fd('\n', 1);
	bin_to_dec(1110011);
	return (0);
}
