# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 13:26:33 by Manny             #+#    #+#              #
#    Updated: 2022/11/25 02:22:11 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar
ARFLAGS = rcs
RM = rm -rf

SRC = ft_flags.c ft_flags_utils.c ft_nbr_len.c ft_print_char.c\
		ft_print_flag.c ft_print_hex.c ft_print_int.c ft_print_ptr.c\
		ft_print_str.c ft_print_unsigned.c ft_printf.c\
		ft_printf_itoa.c ft_printf_utoa.c ft_printf_xtoa.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "\n\e[32m---- (っ▀¯▀)つ libftprintf is compiled! ----\e[0m\n"

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	@echo "\n\e[31m---- ᕦ(ò_óˇ)ᕤ full cleaning done! ----\e[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re 
