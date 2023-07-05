# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 22:03:13 by etetopat          #+#    #+#              #
#    Updated: 2023/07/05 22:03:54 by etetopat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC =
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -I.
	@echo "\n\033[32m---- (っ▀¯▀)つ ... is ready! ----\033[0m\n"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	$(RM) $(OBJ)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ ... is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ ... is gone! ----\033[0m\n"

re: fclean all

mem1:
	valgrind --leak-check=summary ./
mem2:
	valgrind --leak-check=full --show-leak-kinds=all ./
mem3:
	valgrind -s ./

.PHONY : all clean fclean re mem1 mem2 mem3