NAME=notLoser
SRC=main.cpp
OBJ=$(SRC:.cpp=.o)
CFLAG= -std=c++98 -Wall -Wextra -Werror
COMPILER=c++

all : $(NAME)

$(NAME) : $(OBJ)
	$(COMPILER) $(CFLAG) $(OBJ) -o $@

%.o : %.cpp
	$(COMPILER) $(CFLAG) -c $^

clean :
	rm -rf $(NAME) $(OBJ)

re : clean all