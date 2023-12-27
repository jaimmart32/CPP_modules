NAME = UnnecessaryViolence
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf


$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o ${NAME}
			@echo "$(NAME) created."

all: $(NAME)

clean:
		@$(RM) $(OBJ)
		@echo "object files removed."

fclean: clean
		@$(RM) $(NAME)
		@echo "everything removed."

re: fclean all

.PHONY: all clean fclean re