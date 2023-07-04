# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 02:11:23 by Manny             #+#    #+#              #
#    Updated: 2023/07/05 02:15:55 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = Account.cpp
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

.PHONY : all clean fclean re