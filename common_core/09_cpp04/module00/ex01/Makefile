# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 15:30:08 by Manny             #+#    #+#              #
#    Updated: 2023/07/03 16:56:03 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

INC = -I ./inc/

SRC_PATH = ./src/
SRC = 	main.cpp \
		Contact.class.cpp \
		Phonebook.class.cpp

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = ./obj/
OBJ = $(SRC:.cpp=.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(0BJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) -o $@
	@echo "\n\033[32m---- (っ▀¯▀)つ phonebook is ready! ----\033[0m\n"

clean:
	rm -f $(OBJ_PATH)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ phonebook is clean! ----\033[0m\n"

fclean: clean
	rm -f $(NAME)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ phonebook is gone! ----\033[0m\n"

re: fclean all

.PHONY : all clean fclean re