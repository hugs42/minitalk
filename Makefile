# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 14:20:19 by hugsbord          #+#    #+#              #
#    Updated: 2021/06/29 11:24:08 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = server
NAME_2 = client

SRCS_1 =	./srcs/server.c \
			./srcs/utils.c
SRCS_2 =	./srcs/client.c \
			./srcs/utils.c

INC = -I ./includes

FLAGS = -Wall -Wextra -Werror

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
	@echo "\033[93m>> Minitalk compilation\033[0m"
	@clang $(FLAGS) $(INC) -o $(NAME_1) $(OBJS_1)

$(NAME_2): $(OBJS_2)
	@clang $(FLAGS) $(INC) -o $(NAME_2) $(OBJS_2)
	@echo "\033[92mMinitalk's server and client correctly compilated\033[0m"

clean: $(OBJ)
	@echo "\033[93m>> Cleaning objects (.obj)\033[0m"
	@rm -f $(OBJS_1) $(OBJS_2)

fclean: clean
	@echo "\033[93m>> Cleaning executables\033[0m"
	@rm -f $(NAME_1) $(NAME_2)

re:
	@make fclean
	@make all

bonus: all

.PHONY: all, clean, fclean, re, bonus
