NAME = phoneBook

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = includes

VPATH = ./src ./src/classes
SRC = main.cpp PhoneBook.cpp Contacts.cpp Utils.cpp


OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INC_DIR)

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