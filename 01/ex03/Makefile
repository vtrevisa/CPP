#----SPECIFICS---------------------------------------------------------------------------------

NAME = fight
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

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

v: all
	valgrind --leak-check=full ./$(NAME)

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