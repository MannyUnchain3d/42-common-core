# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 22:03:13 by etetopat          #+#    #+#              #
#    Updated: 2023/07/10 13:44:37 by etetopat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = weapons

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
CC = g++ -g3
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# ***** INCLUDES ******* #
INC = -I ./inc/

# ***** SOURCES ******** #
SRC_PATH = ./src/
SRC = main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp
SRCS = $(addprefix $(SRC_PATH), $(SRC))

# ***** OBJECTS ******** #
OBJ_PATH = ./obj/
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

# ***** RULES ********** #
all: $(OBJ_PATH) $(NAME)

 $(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -I.
	@echo "\n\033[32m---- (っ▀¯▀)つ $(NAME) is ready! ----\033[0m\n"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	$(RM) $(OBJ)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ $(NAME) is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME) $(OBJ_PATH)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----\033[0m\n"

re: fclean all

# ***** MEMORY LEAKS **** #
mem1:
	valgrind --leak-check=summary ./$(NAME)
mem2:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
mem3:
	valgrind -s ./$(NAME)

.PHONY : all clean fclean re mem1 mem2 mem3