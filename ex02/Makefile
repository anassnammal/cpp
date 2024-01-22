NAME=GlobalBanksters
SRC=tests.cpp Account.cpp
OBJ=$(SRC:.cpp=.o)
FLG=-Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
	c++ $(FLG) $(OBJ) -o $@

%.o: %.cpp
	c++ $(FLG) -c $<

clean:
	rm -rf $(NAME) $(OBJ)

re: clean $(NAME)
