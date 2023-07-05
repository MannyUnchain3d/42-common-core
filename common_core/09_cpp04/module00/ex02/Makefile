# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 02:11:23 by Manny             #+#    #+#              #
#    Updated: 2023/07/05 19:42:57 by etetopat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = no_money_no_honey

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -I.
	@echo "\n\033[32m---- (っ▀¯▀)つ account is ready! ----\033[0m\n"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	$(RM) $(OBJ)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ account is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ account is gone! ----\033[0m\n"

re: fclean all

mem1:
	valgrind --leak-check=summary ./no_money_no_honey
mem2:
	valgrind --leak-check=full --show-leak-kinds=all ./no_money_no_honey
mem3:
	valgrind -s ./no_money_no_honey

.PHONY : all clean fclean re mem1 mem2 mem3