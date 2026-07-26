NAME = sarab_mota3adid!

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Zombie.cpp zombieHorde.cpp

OSRC = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OSRC)
	@c++ $(FLAGS) $(OSRC) -o $(NAME)

%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OSRC)

fclean:
	@rm -f $(OSRC) $(NAME)

re: fclean all

ra: all clean