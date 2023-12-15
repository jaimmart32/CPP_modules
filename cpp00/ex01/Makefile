NAME = phonebook

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = blalbblablablablala
OBJ = $(SRC:.cpp=.o)

$(NAME):	$(OBJ)
			${CC} ${FLAGS} ${OBJ} -o ${NAME}
			@echo "$(NAME) created."

all:	$(NAME)

clean:
			@$(RM) $(OBJ)
			@echo "object files removed."

fclean:	clean
			@$(RM) $(NAME)
			@echo "everything removed."
re:	fclean all

.PHONY: all clean fclean re