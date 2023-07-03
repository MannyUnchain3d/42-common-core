# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 02:28:22 by Manny             #+#    #+#              #
#    Updated: 2023/07/03 15:57:53 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "\n\033[32m---- (っ▀¯▀)つ megaphone is ready! ----\033[0m\n"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ megaphone is clean! ----\033[0m\n"

fclean: clean
	rm -f $(NAME)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ megaphone is gone! ----\033[0m\n"

re: fclean all

.PHONY : all clean fclean re