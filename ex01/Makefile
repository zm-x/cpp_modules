CC = c++

NAME = phonebook

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Contact.cpp helper_functions.cpp \
	main.cpp Phonebook.cpp

OBJ = ${SRC:.cpp=.o}

all : ${NAME}

${NAME} : ${OBJ}
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

ra: all clean