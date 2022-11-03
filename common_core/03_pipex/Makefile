# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 13:33:09 by Manny             #+#    #+#              #
#    Updated: 2022/10/25 21:09:00 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= pipex
#PROG_B	= pipex_bonus

SRCS	= srcs/pipex.c srcs/utils.c
OBJS	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

#SRCS_B	= srcs/pipex_bonus.c srcs/utils.c srcs/utils_bonus.c
#OBJS_B	= {SRCS_B:.c=.o}
#MAIN_B	= srcs/pipex_bonus.c

HEADER	= -Iinclude

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

.c.o:		 %.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all:		${PROG}

${PROG}:	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@${CC} ${OBJS} -Llibft -lft -o ${PROG}
					@echo "\033[32mPipex compiled!\n"

#bonus:		${PROG_B}

#${PROG_B}:	${OBJS_B}

#					@echo "\033[33m----Compiling lib----"
#					@make re -C ./libft
#					@${CC} ${OBJS_B} -Llibft -lft -o ${PROG_B}
#					@echo "\033[32mPipex bonus compiled!\n"

clean:
					@make clean -C ./libft
					@rm -rf ${OBJS} ${OBJS_B}

fclean:		clean
					@make fclean -C ./libft
					@rm -f ${NAME}
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING!!!\n"

re:			fclean all

#re_bonus:	fclean bonus

.PHONY: all clean fclean re re_bonus bonus