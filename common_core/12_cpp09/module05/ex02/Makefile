# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 19:52:24 by Manny             #+#    #+#              #
#    Updated: 2023/11/13 20:32:40 by Manny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** EXECUTABLE ***** #
NAME = Forms

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
SRC_DIR = ./src/
SRC = 	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
SRCS = $(addprefix $(SRC_DIR), $(SRC))

# ***** OBJECTS ******** #
OBJ_DIR = ./obj/
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

# ***** RULES ********** #
all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(MAGENTA) $(CC) $(CFLAGS) $(INC) -c $< -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\n$(BLUE) $(CC) $(CFLAGS) $(OBJS) -o $@ $(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) is ready! ----$(NC)\n"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "\n$(YELLOW) $(RM) $(OBJ_DIR) $(NC)"
	@echo "\n$(RED)---- ᕦ(ò_óˇ)ᕤ $(NAME) is clean! ----$(NC)\n"

fclean: clean
	@$(RM) $(NAME) *_shrubbery
	@echo "\n$(YELLOW) $(RM) $(NAME) $(NC)"
	@echo "\n$(RED)---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----$(NC)\n"

re: fclean all

# ***** MEMORY LEAKS **** #
mem1:
	valgrind --leak-check=summary ./$(NAME)
mem2:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
mem3:
	valgrind -s ./$(NAME)

.PHONY : all clean fclean re mem1 mem2 mem3