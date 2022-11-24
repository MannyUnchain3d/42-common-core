# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 19:14:30 by Manny             #+#    #+#              #
#    Updated: 2022/11/23 23:21:42 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- ANSI COLOR CODES -- #
END				=	\e[0m
BOLD			=	\e[1m
UNDER			=	\e[4m
REV				=	\e[7m
GREY			=	\e[30m
RED				=	\e[31m
GREEN			=	\e[32m
YELLOW			=	\e[33m
BLUE			=	\e[34m
PURPLE			=	\e[35m
CYAN			=	\e[36m
WHITE			=	\e[37m
# ---------------------- #

NAME			=	libft.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	ft_isalnum.c ft_isdigit.c ft_memcpy.c ft_putchar_fd.c\
					ft_putstr_fd.c ft_strdup.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c\
					ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memchr.c\
					ft_memmove.c ft_putendl_fd.c ft_split.c ft_strjoin.c ft_strlen.c\
					ft_strnstr.c ft_substr.c ft_atoi.c ft_calloc.c ft_isascii.c ft_itoa.c\
					ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strlcat.c\
					ft_strmapi.c ft_strrchr.c ft_tolower.c ft_striteri.c
SRC_B			= 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_DIR			=	obj
OBJ				=	$(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_B			=	$(SRC_B:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				$(OBJ_DIR) $(OBJ) $(OBJ_B)
					$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_B)
					@echo "$(GREEN)---- (っ▀¯▀)つ libft bonus is compiled! ----$(END)\n"

$(NAME):			$(OBJ_DIR) $(OBJ)
					$(AR) $(ARFLAGS) $(NAME) $(OBJ)
					@echo "$(GREEN)---- (っ▀¯▀)つ libft is compiled! ----$(END)\n"

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(RM) $(NAME)
					@echo "$(RED)---- ᕦ(ò_óˇ)ᕤ full cleaning done! ----$(END)\n"

re:					fclean all

re_bonus:			fclean bonus

.PHONY: 			all clean fclean re bonus