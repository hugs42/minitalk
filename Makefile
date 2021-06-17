# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 14:20:19 by hugsbord          #+#    #+#              #
#    Updated: 2021/06/17 09:59:28 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = server
NAME_2 = client

SRCS_1 = ./srcs/server.c
SRCS_2 = ./srcs/client.c

INC = -I ./includes

FLAGS = -Wall -Wextra -Werror

LIB_DIR = -L ./libft
LIBFT = ./libft/libft.a

OBJS_1 = $(SRCS_1:.c=.o)
OBJS_2 = $(SRCS_2:.c=.o)

%.o: %.c
	@clang $(INC) -o $@ -c $<

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJS_1)
	@echo "\033[96m"
	@echo "                            :::      ::::::::"
	@echo "                          :+:      :+:    :+:"
	@echo "    42_cursus:          +:+ +:+         +:+"
	@echo "    MINITALK          +#+  +:+       +#+"
	@echo "                    +#+#+#+#+#+   +#+"
	@echo "                          #+#    #+#"
	@echo "                         ###   ########.fr\033[0m"
	@echo "\033[0m"
	@echo "\033[93m>> Libft compilation\033[0m"
	@make -C libft
	@echo "\033[93m>> Minitalk compilation\033[0m"
	@clang $(FLAGS) $(INC) -o $(NAME_1) $(OBJS_1) $(LIBFT)

$(NAME_2): $(OBJS_2)
	@clang $(FLAGS) $(INC) -o $(NAME_2) $(OBJS_2) $(LIBFT)
	@echo "\033[92mMinitalk's server and client correctly compilated\033[0m"


clean: $(OBJ)
	@echo "\033[93m>> Cleaning objects (.obj)\033[0m"
	@make $@ -C libft
	@rm -f $(OBJS_1) $(OBJS_2)

fclean: clean
	@make $@ -C libft
	@rm -f $(NAME_1) $(NAME_2)

re:
	@make fclean
	@make all

bonus: $(NAME_1) $(NAME_2)

.PHONY: all, clean, fclean, re, bonus
