# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 02:34:36 by Manny             #+#    #+#              #
#    Updated: 2023/07/12 03:03:18 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = harlFilter

# ***** COMPILATION **** #
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# ***** SOURCES ******** #
SRC = Harl.cpp main.cpp

# ***** OBJECTS ******** #
OBJ = $(SRC:.cpp=.o)

# ***** RULES ********** #
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
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