# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 16:18:29 by Manny             #+#    #+#              #
#    Updated: 2023/07/09 03:46:45 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = push_swap
BONUS = checker

# ***** COMPILATION **** #
CC = gcc -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# ***** INCLUDES ******* #
INC = -I ./

# ***** LIBFT ********** #
LIBFTDIR = ./libft/
LIBFT = -L libft -lft

# ***** SOURCES ******* #
SRC_PATH = src/
SRC = cost.c init.c input_check.c main.c move.c position.c push.c rev_rotate.c \
		rotate.c sort_3nb.c sort.c stack.c swap.c utils.c
SRC_BONUS = cost.c init.c input_check.c move.c position.c push.c rev_rotate.c \
		rotate.c sort_3nb.c sort.c stack.c swap.c utils.c checker.c

# ***** OBJECTS ******* #
OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_BONUS = $(addprefix $(OBJ_PATH), $(OBJ_BONUS))

# ***** RULES ********* #
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)
	@echo "\n\033[32m---- (っ▀¯▀)つ $(NAME) is ready! ----\033[0m\n"

$(BONUS): $(OBJS_BONUS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS) $(LIBFT)
	@echo "\n\033[32m---- (っ▀¯▀)つ checker is ready! ----\033[0m\n"

bonus: $(OBJ_PATH) $(BONUS)

clean:
	$(RM) $(OBJ_PATH)
	@make clean -C $(LIBFTDIR)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ $(NAME) is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME) $(BONUS)
	@make fclean -C $(LIBFTDIR)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ $(NAME) and checker are gone! ----\033[0m\n"

re: fclean all

rebonus: fclean bonus

test2: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test3: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test1000: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

# ***** MEMORY LEAKS *** #
mem1:
	valgrind --leak-check=summary ./$(NAME)
mem2:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
mem3:
	valgrind -s ./$(NAME)

.PHONY: all bonus clean fclean re rebonus test2 test3 test5 test100 test500 test1000 mem1 mem2 mem3