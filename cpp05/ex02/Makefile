NAME = Buroexecution

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp
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