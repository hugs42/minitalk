/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:29:41 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/24 09:55:21 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

#define MINITALK_H

#include "./../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h> 

typedef struct	s_msg
{
	char		c;
	size_t		len;
}				t_msg;

# define SUCCESS 0
# define ERROR -1

#endif
