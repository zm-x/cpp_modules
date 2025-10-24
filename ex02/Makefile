CC = c++

NAME = Account

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp

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
