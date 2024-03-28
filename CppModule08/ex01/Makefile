NAME = span
SRCS = main.cpp Span.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
INCS = Span.hpp
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
CC = c++

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp Span.hpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

