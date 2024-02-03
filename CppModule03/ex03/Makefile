NAME=DiamondTrap
SRC=main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ=$(SRC:.cpp=.o)
INC=ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
FLAGS=-std=c++98 -Wall -Wextra -Werror
COMPILER=c++

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(COMPILER) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all