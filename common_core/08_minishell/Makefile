# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 18:47:27 by Manny             #+#    #+#              #
#    Updated: 2023/07/09 03:51:33 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = minishell
NAME_B = minishell_bonus

# ***** COMPILATION **** #
CC = gcc -g3 #-fsanitize=address
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

UNAME = $(shell uname -s)
ifeq ($(UNAME), Darwin)
INC = -I ./inc -I $(LIBFT_PATH) -I /usr/local/opt/readline/include
READ = -L /usr/local/opt/readline/lib -l readline
else
INC = -I ./inc -I $(LIBFT_PATH)
READ = -l readline
endif

# ***** LIBFT ********** #
LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a

# ***** SOURCES ******* #
SRC_PATH = ./src/
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

SRC_BO =	$(filter-out parser/parse_2.c,$(SRC)) \
		parser/parse_2_bonus.c \
		parser/wildling_bonus.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

# ***** OBJECTS ******* #
OBJ_PATH = ./obj/
OBJ = $(SRC:.c=.o)
OBJ_BO = $(SRC_BO:.c=.o)

OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_BO = $(addprefix $(OBJ_PATH), $(OBJ_BO))

# ***** RULES ********* #
all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	mkdir -p $(OBJ_PATH)builtins
	mkdir -p $(OBJ_PATH)execution
	mkdir -p $(OBJ_PATH)env
	mkdir -p $(OBJ_PATH)parser
	mkdir -p $(OBJ_PATH)redirections
	mkdir -p $(OBJ_PATH)utils

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus: $(OBJ_PATH) $(LIBFT) $(NAME_B)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT) $(READ) -o $@
	@echo "\n\033[32m---- (っ▀¯▀)つ $(NAME) is ready! ----\033[0m\n"

$(NAME_B): $(OBJS_BO)
	$(CC) $(CFLAGS) $(OBJS_BO) $(INC) $(LIBFT) $(READ) -o $@
	@echo "\n\033[32m---- (っ▀¯▀)つ $(NAME) bonus is ready! ----\033[0m\n"

$(LIBFT):
	make bonus -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ $(NAME) is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME) $(NAME_B)
	@make fclean -C $(LIBFT_PATH)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----\033[0m\n"

re: fclean all

rebonus: fclean bonus

# ***** MEMORY LEAKS *** #
mem1:
	valgrind --leak-check=summary ./$(NAME)
mem2:
	valgrind --leak-check=full --show-leak-kinds=definite,possible ./$(NAME)
mem3:
	valgrind -s ./$(NAME)

.PHONY: all clean fclean re bonus rebonus mem1 mem2 mem3