# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/20 12:43:08 by cnkosi            #+#    #+#              #
#    Updated: 2017/09/22 23:54:45 by wphokomp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

SRC = src/main.c src/memory.c src/cmds.c src/env.c lib/libft.a

FLAGS = clang -Wextra -Wall -Werror -g -I includes -o

all: $(NAME)

$(NAME): 
	@make -C lib/ fclean && make -C lib/ all
	@$(FLAGS) $(NAME) $(SRC)
	@clear 
	@echo "42sh is compiled successfully"

clean:
	make -C lib/ clean
	@rm -fr 42sh.dSYM *.o
	@clear
	@echo "42sh cleaned successfully"

fclean: clean
	make -C lib/ fclean
	@rm -f $(NAME) *.o
	@clear
	@echo "42sh is fully cleaned"

re: fclean all
	@clear
	@echo "42sh is recompiled successfully"

norm:
	@clear
	@echo "norminette 42sh"
	@norminette src/* includes/*
