/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:28:56 by hugsbord          #+#    #+#             */
/*   Updated: 2021/10/01 13:46:30 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

static t_msg	g_msg;

char	*add_char(char *str, char c)
{
	int		i;
	char	*new_str;

	new_str = "test";
	if ((new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 6)) == NULL)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	i++;
	new_str[i] = '\0';
	return (new_str);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	char *str;

	str = NULL;
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
	struct sigaction	sa_signal;
	sigset_t			block_mask;
	int					pid;

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
	ft_putstr_fd("Server launched:\nMy PID is: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	g_msg.len = 0;
	g_msg.c = 0;
	while (42)
	{
		pause();
//		if (signal(SIGUSR1, signal_handler) == SIG_ERR)
//			exit(0);
//		if (signal(SIGUSR2, signal_handler) == SIG_ERR)
//			exit(0);
	}
	return (0);
}
