NAME = ifelse

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Harl.cpp

OSRC = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OSRC)
	@c++ $(FLAGS) $(OSRC) -o $(NAME)

%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OSRC)

fclean: clean
	@rm -f $(NAME)

re: fclean all

ra: all clean
