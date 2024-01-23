NAME=phonebook
SRC=Contact.cpp PhoneBook.cpp app.cpp
OBJ=$(SRC:.cpp=.o)
FLG=-Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
	c++ $(FLG) $(OBJ) -o $@

%.o: %.cpp
	c++ $(FLG) -c $<

clean:
	rm -rf $(NAME) $(OBJ)

re: clean $(NAME)
