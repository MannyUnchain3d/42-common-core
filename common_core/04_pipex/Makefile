# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 13:33:09 by Manny             #+#    #+#              #
#    Updated: 2023/07/17 02:55:44 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = pipex
NAME_B = pipex_bonus

# ***** COLORS ********* #
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
MAGENTA	= \033[0;35m
CYAN	= \033[0;36m
BOLD	= \033[1m
ITALIC	= \033[3m
ULINE	= \033[4m
BLINK	= \033[5m
NC		= \033[0m

# ***** COMPILATION **** #
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
RM = -rm -rf

# ***** INCLUDES ******* #
INC = -I ./inc/ -I $(LIBFT_DIR)

# ***** LIBFT ********** #
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
lIBFTFLAGS = -L $(LIBFT_DIR) -lft

# ***** SOURCES ******** #
SRC_DIR = ./src/
SRC = pipex.c utils.c
SRC_B = pipex_bonus.c utils.c utils_bonus.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRCS_B = $(addprefix $(SRC_DIR), $(SRC_B))

# ***** OBJECTS ******** #
OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJS_B = $(addprefix $(OBJ_DIR), $(OBJ_B))

# ***** RULES ********** #
all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(MAGENTA) $(CC) $(CFLAGS) $(INC) -c $< -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus: $(OBJ_DIR) $(LIBFT) $(NAME_B)

$(NAME): $(LIBFT) $(OBJS)
	@echo "\n$(BLUE) $(CC) $(OBJS) $(lIBFTFLAGS) -o $(NAME) $(NC)"
	@$(CC) $(OBJS) $(lIBFTFLAGS) -o $(NAME)
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) is ready! ----$(NC)\n"

$(NAME_B): $(OBJS_B)
	@echo "\n$(BLUE) $(CC) $(CFLAGS) $(OBJS_B) $(INC) $(LIBFT) $(lIBFTFLAGS) -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(OBJS_B) $(INC) $(LIBFT) $(lIBFTFLAGS) -o $@
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) bonus is ready! ----$(NC)\n"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	$(RM) $(OBJ_DIR)
	@make clean -sC $(LIBFT_DIR)
	@echo "\n$(RED)---- ᕦ(ò_óˇ)ᕤ $(NAME) is clean! ----$(NC)\n"

fclean: clean
	$(RM) $(NAME) $(NAME_B)
	@make fclean -sC $(LIBFT_DIR)
	@echo "\n$(RED)---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----$(NC)\n"

re: fclean all

re_bonus: fclean bonus

# ***** MEMORY LEAKS *** #
mem1:
	valgrind --leak-check=summary ./$(NAME)
mem2:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
mem3:
	valgrind -s ./$(NAME)

.PHONY : all clean fclean re bonus re_bonus mem1 mem2 mem3