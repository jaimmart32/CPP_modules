NAME = Dynamic_casting

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address

SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp functions.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
			@echo "$(NAME) created."

all: $(NAME)

clean:
			@rm -rf $(OBJ) *_shrubbery
			@echo "object files removed."

fclean: clean
			@rm -rf $(NAME)
			@echo "everything removed."

re: fclean all

.PHONY: all clean fclean re