NAME = MoarBrainz

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror  -std=c++98

RM = rm -rf

SRC = Zombie.cpp zombieHorde.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME):	$(OBJ)
			${CXX} ${OBJ} -o ${NAME}
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
