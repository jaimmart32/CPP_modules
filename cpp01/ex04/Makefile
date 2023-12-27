NAME = ReplaceStrings

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
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