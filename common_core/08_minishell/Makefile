# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 18:47:27 by Manny             #+#    #+#              #
#    Updated: 2023/07/17 23:06:28 by etetopat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = minishell
NAME_B = minishell_bonus

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
RM = rm -rf

# ***** INCLUDES ******* #
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	INC = -I ./inc -I $(LIBFT_DIR)
	READ = -l readline
else
	INC = -I ./inc -I $(LIBFT_DIR) -I /usr/local/opt/readline/include
	READ = -L /usr/local/opt/readline/lib -l readline

endif

# ***** LIBFT ********** #
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

# ***** SOURCES ******* #
SRC_DIR = ./src/
SRC = 	main.c \
		builtins/cd_builtin.c \
		builtins/echo_builtin.c \
		builtins/env_builtin.c \
		builtins/exit_builtin.c \
		builtins/export_builtin.c \
		builtins/pwd_builtin.c \
		builtins/unset_builtin.c \
		env/env.c \
		env/set_env.c \
		execution/execute_cmd.c \
		execution/execute_utils.c \
		execution/execute.c \
		execution/execute_2.c \
		execution/parse_path.c \
		execution/signal_exit_status.c \
		execution/signal_set.c \
		execution/termios.c \
		parser/check_token.c \
		parser/exp_env.c \
		parser/expansion.c \
		parser/group_cmd.c \
		parser/group_cmd2.c \
		parser/group_cmd3.c \
		parser/group_cmd4.c \
		parser/input_split.c \
		parser/metachar.c \
		parser/parse_1.c \
		parser/parse_2.c \
		parser/word_util.c \
		redirections/pipe.c \
		redirections/file_io.c \
		redirections/heredoc_imp.c \
		redirections/heredoc_utils.c \
		redirections/place_fd.c \
		utils/clean.c \
		utils/error.c \
		utils/exit.c \
		utils/init_data.c

SRC_B =	$(filter-out parser/parse_2.c,$(SRC)) \
		parser/parse_2_bonus.c \
		parser/wildling_bonus.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

# ***** OBJECTS ******* #
OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJS_B = $(addprefix $(OBJ_DIR), $(OBJ_B))

# ***** RULES ********* #
all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)builtins
	@mkdir -p $(OBJ_DIR)execution
	@mkdir -p $(OBJ_DIR)env
	@mkdir -p $(OBJ_DIR)parser
	@mkdir -p $(OBJ_DIR)redirections
	@mkdir -p $(OBJ_DIR)utils

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(MAGENTA) $(CC) $(CFLAGS) $(INC) -c $< -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus: $(OBJ_DIR) $(LIBFT) $(NAME_B)

$(NAME): $(OBJS)
	@echo "\n$(BLUE) $(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT) $(READ) -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT) $(READ) -o $@
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) is ready! ----$(NC)\n"

$(NAME_B): $(OBJS_B)
	@echo "\n$(BLUE) $(CC) $(CFLAGS) $(OBJS_B) $(INC) $(LIBFT) $(READ) -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(OBJS_B) $(INC) $(LIBFT) $(READ) -o $@
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) bonus is ready! ----$(NC)\n"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "\n$(YELLOW) $(RM) $(OBJ_DIR) $(NC)"
	@make clean -sC $(LIBFT_DIR)
	@echo "\n$(RED)---- ᕦ(ò_óˇ)ᕤ $(NAME) is clean! ----$(NC)\n"

fclean: clean
	@$(RM) $(NAME) $(NAME_B)
	@echo "\n$(YELLOW) $(RM) $(NAME) $(NAME_B) $(NC)"
	@make fclean -sC $(LIBFT_DIR)
	@echo "\n$(RED)---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----$(NC)\n"

re: fclean all

re_bonus: fclean bonus

# ***** MEMORY LEAKS *** #
mem1:
	valgrind --leak-check=summary ./$(NAME)
mem2:
	valgrind --leak-check=full --show-leak-kinds=definite,possible ./$(NAME)
mem3:
	valgrind -s ./$(NAME)

.PHONY: all clean fclean re bonus re_bonus mem1 mem2 mem3