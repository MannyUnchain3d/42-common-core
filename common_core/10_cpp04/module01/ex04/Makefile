# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 13:48:00 by etetopat          #+#    #+#              #
#    Updated: 2023/07/12 13:50:57 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = better_sed

# ***** COMPILATION **** #
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# ***** INCLUDES ******* #
INC = -I ./

# ***** SOURCES ******** #
SRC = main.cpp BetterSed.cpp

# ***** OBJECTS ******** #
OBJ = $(SRC:.cpp=.o)

# ***** RULES ********** #
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(INC)
	@echo "\n\033[32m---- (っ▀¯▀)つ $(NAME) is ready! ----\033[0m\n"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@echo "\n\033[31m---- (╯°□°)╯︵ ┻━┻ $(NAME) is clean! ----\033[0m\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\n\033[31m---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----\033[0m\n"

re: fclean all

.PHONY : all clean fclean re