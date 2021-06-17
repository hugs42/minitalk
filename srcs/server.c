/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:28:56 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/17 09:45:18 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

int		main(void)
{
	int		pid;
	char	*display_pid;

	pid = getpid();
	display_pid = ft_itoa(pid);
	return (0);
}
