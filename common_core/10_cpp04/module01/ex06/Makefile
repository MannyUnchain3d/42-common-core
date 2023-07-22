# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 02:34:36 by Manny             #+#    #+#              #
#    Updated: 2023/07/22 17:51:58 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = harlFilter

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
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# ***** INCLUDES ******* #
INC = -I ./

# ***** SOURCES ******** #
SRC = Harl.cpp main.cpp

# ***** OBJECTS ******** #
OBJ = $(SRC:.cpp=.o)

# ***** RULES ********** #
all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n$(BLUE) $(CC) $(CFLAGS) $(OBJ) -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(INC)
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) is ready! ----$(NC)\n"

%.o: %.cpp
	@echo "$(MAGENTA) $(CC) $(CFLAGS) -c $< -o $@ $(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "\n$(YELLOW) $(RM) $(OBJ) $(NC)"
	@echo "\n$(RED)---- (╯°□°)╯︵ ┻━┻ $(NAME) is clean! ----$(NC)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "\n$(YELLOW) $(RM) $(NAME) $(NC)"
	@echo "\n$(RED)---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----$(NC)\n"

re: fclean all

.PHONY : all clean fclean re