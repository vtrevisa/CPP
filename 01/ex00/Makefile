#----SPECIFICS---------------------------------------------------------------------------------

NAME = zombies
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

#----DIRS--------------------------------------------------------------------------------------

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = includes
VPATH = ./src ./src/classes

#----FLAGS-------------------------------------------------------------------------------------

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INC_DIR)

#----OBECTS------------------------------------------------------------------------------------

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

#----FUNCTIONS----------------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(CFLAGS) $(OBJ) -o $@
	@echo "link $@"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@c++ $(CFLAGS) -c $< -o $@
	@echo "compile $<"

clean:
	@rm -f $(OBJ)
	@echo "clean"

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME) $(OBJ)
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean re