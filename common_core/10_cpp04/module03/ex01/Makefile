# ***** EXECUTABLE ***** #
NAME = scavtrap

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
SRC = ClapTrap.cpp main.cpp ScavTrap.cpp
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
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)
	@echo "\n$(GREEN)---- (っ▀¯▀)つ $(NAME) is ready! ----$(NC)\n"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_PATH)
	@echo "\n$(RED)---- (╯°□°)╯︵ ┻━┻ $(NAME) is clean! ----$(NC)\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\n$(RED)---- (╯°□°）╯︵ ┻━┻ $(NAME) is gone! ----$(NC)\n"

re: fclean all

# ***** MEMORY LEAKS **** #
mem1:
	valgrind --leak-check=summary ./$(NAME)
mem2:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
mem3:
	valgrind -s ./$(NAME)

.PHONY : all clean fclean re mem1 mem2 mem3