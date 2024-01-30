NAME=Fixed
SRC=main.cpp Fixed.cpp
OBJ=$(SRC:.cpp=.o)
FLAGS=-std=c++98 -Wall -Wextra -Werror
COMP=c++

all: $(NAME)

$(NAME): $(OBJ) Fixed.hpp
	$(COMP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all