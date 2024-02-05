NAME = Interface
SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
INCS = AMateria.hpp Ice.hpp Cure.hpp
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
CC = c++

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp AMateria.hpp Ice.hpp Cure.hpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

