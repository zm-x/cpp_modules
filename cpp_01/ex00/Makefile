NAME = BraiiiiiiinnnzzzZ

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp newZombie.cpp \
	randomChump.cpp Zombie.cpp

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