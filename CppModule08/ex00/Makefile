NAME = efind
SRCS = main.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
INCS = easyfind.hpp
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
CC = c++

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp 
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

