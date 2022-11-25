# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 13:26:33 by Manny             #+#    #+#              #
#    Updated: 2022/11/25 16:32:10 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar
ARFLAGS = rcs
RM = rm -rf

SRC_DIR = src
SRC = ft_flags.c ft_flags_utils.c ft_nbr_len.c ft_print_char.c\
		ft_print_flag.c ft_print_hex.c ft_print_int.c ft_print_ptr.c\
		ft_print_str.c ft_print_unsigned.c ft_printf.c\
		ft_printf_itoa.c ft_printf_utoa.c ft_printf_xtoa.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(SRC_DIR)/$(OBJ_DIR)/%.o)

HEADER = -Iinclude

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(SRC_DIR)/$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(SRC_DIR)/$(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "\n\e[32m---- (っ▀¯▀)つ libftprintf is compiled! ----\e[0m\n"

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(SRC_DIR)/$(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	@echo "\n\e[31m---- ᕦ(ò_óˇ)ᕤ full cleaning done! ----\e[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re 
