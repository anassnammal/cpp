NAME = identify
SRCS = main.cpp Base.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
INCS = Base.hpp A.hpp B.hpp C.hpp
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
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

