# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 16:18:29 by Manny             #+#    #+#              #
#    Updated: 2022/12/26 16:03:43 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC = -I ./push_swap.h

SRC_PATH = src/
SRC = cost.c move.c init.c input_check_utils.c input_check.c main.c \
		position.c push.c rev_rotate.c rotate.c sort_3nb.c sort.c \
		stack.c swap.c utils.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ_PATH = obj/
OBJ = (SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re