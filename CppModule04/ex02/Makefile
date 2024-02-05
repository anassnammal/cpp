NAME = Abstract
SRCS = main.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
INCS = AAnimal.hpp Dog.hpp Cat.hpp Brain.hpp
CPPFLAGS = -g -std=c++98 -Wall -Wextra -Werror
CC = c++

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

