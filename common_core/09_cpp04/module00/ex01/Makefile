# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 15:30:08 by Manny             #+#    #+#              #
#    Updated: 2023/07/04 22:02:29 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = angry-phonebook

CC = g++ -g
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

INC = -I ./inc/

SRC_PATH = ./src/
SRC = 	main.cpp \
		Contact.class.cpp \
		PhoneBook.class.cpp

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = ./obj/
OBJ = $(SRC:.cpp=.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)
	@echo "\n\033[32m---- (っ▀¯▀)つ angry-phonebook is ready! ----\033[0m\n"

clean:
	$(RM) $(OBJ_PATH)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ angry-phonebook is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ angry-phonebook is gone! ----\033[0m\n"

re: fclean all

mem1:
	valgrind --leak-check=summary ./angry-phonebook
mem2:
	valgrind --leak-check=full --show-leak-kinds=definite,possible ./angry-phonebook
mem3:
	valgrind -s ./angry-phonebook

.PHONY : all clean fclean re mem1 mem2 mem3