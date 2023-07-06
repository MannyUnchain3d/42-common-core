# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 22:03:13 by etetopat          #+#    #+#              #
#    Updated: 2023/07/06 18:13:18 by etetopat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = brainzz

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

INC = -I ./inc/

SRC_PATH = ./src/
SRC = main.cpp \
	  newZombie.cpp \
	  randomChump.cpp \
	  Zombie.cpp
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = ./obj/
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))


all: $(OBJ_PATH) $(NAME)

 $(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -I.
	@echo "\n\033[32m---- (っ▀¯▀)つ brainzz is ready! ----\033[0m\n"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	$(RM) $(OBJ)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ brainzz is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ brainzz is gone! ----\033[0m\n"

re: fclean all

mem1:
	valgrind --leak-check=summary ./brainzz
mem2:
	valgrind --leak-check=full --show-leak-kinds=all ./brainzz
mem3:
	valgrind -s ./brainzz

.PHONY : all clean fclean re mem1 mem2 mem3