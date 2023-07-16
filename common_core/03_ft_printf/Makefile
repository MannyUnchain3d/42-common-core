# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 13:26:33 by Manny             #+#    #+#              #
#    Updated: 2023/07/17 03:33:16 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = libftprintf.a

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
AR = ar
ARFLAGS = rcs
RM = rm -rf

# ***** INCLUDES ******* #
INC = -I ./inc/ -I $(LIBFT_DIR)

# ***** LIBFT ********** #
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# ***** SOURCES ******** #
SRC_DIR = ./src/
SRC = ft_flags.c ft_flags_utils.c ft_nbr_len.c ft_print_char.c\
		ft_print_flag.c ft_print_hex.c ft_print_int.c ft_print_ptr.c\
		ft_print_str.c ft_print_unsigned.c ft_printf.c\
		ft_printf_itoa.c ft_printf_utoa.c ft_printf_xtoa.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))

# ***** OBJECTS ******** #
OBJ_DIR = ./obj/
OBJ = $(SRC:%.c=%.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

# ***** RULES ********** #
all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(MAGENTA) $(CC) $(CFLAGS) $(INC) -c $< -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus: all

$(NAME): $(OBJS) $(LIBFT)
	@echo "\n$(BLUE) $(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@ $(NC)"
	@$(AR) $(ARFLAGS) $@ $(OBJS) $(LIBFT)
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) is ready! ----$(NC)\n"

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

.PHONY: all clean fclean re bonus re_bonus mem1 mem2 mem3