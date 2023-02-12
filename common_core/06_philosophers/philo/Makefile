# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 23:18:49 by Manny             #+#    #+#              #
#    Updated: 2023/02/12 19:33:40 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc -g3 -pthread #-fsanitize=thread
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC = -I ./

SRC_PATH = src/
SRC = exit.c init.c input_check.c main.c manager.c time.c output.c philosopher.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "\n\033[32m---- (っ▀¯▀)つ philo is ready! ----\033[0m\n"

clean:
	$(RM) $(OBJ_PATH)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ philo is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ philo is gone! ----\033[0m\n"

re: fclean all

.PHONY: all clean fclean re