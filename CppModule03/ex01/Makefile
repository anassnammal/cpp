NAME= ScavTrap
SRC=main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ=$(SRC:.cpp=.o)
FLAGS=-std=c++98 -Wall -Wextra -Werror
COMPILER=c++

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all