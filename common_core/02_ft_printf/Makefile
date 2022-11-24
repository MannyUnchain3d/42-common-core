# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 13:26:33 by Manny             #+#    #+#              #
#    Updated: 2022/11/24 14:15:47 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END = \e[0m
BOLD = \e[1m
UNDER = \e[4m
REV = \e[7m
GREY = \e[30m
RED = \e[31m
GREEN = \e[32m
YELLOW = \e[33m
BLUE = \e[34m
PURPLE = \e[35m
CYAN = \e[36m
WHITE = \e[37m

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
AR = ar
ARFLAGS = rcs

SRC = ft_printf ft_print_char ft_print_str ft_print_hex ft_print_int \
		ft_print_ptr ft_print_unsigned ft_nbr_len ft_flags ft_flags_utils \
		ft_print_flag ft_printf_itoa ft_printf_utoa ft_printf_xtoa
SRCS = $(addsuffix .c, $(SRC))

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:%.c
					$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
			cp $(LIBFT) $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)
			@echo "\n$(GREEN)---- (っ▀¯▀)つ libftprintf is compiled! ----$(END)\n"

$(LIBFT):
			make -C $(LIBFT_PATH) all

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

clean:
		make -C $(LIBFT_PATH) clean
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME) ./libft/libft.a
		@echo "\n$(RED)---- ᕦ(ò_óˇ)ᕤ full cleaning done! ----$(END)\n"

re: fclean all

.PHONY: all clean fclean re libft
