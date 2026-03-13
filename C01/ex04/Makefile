NAME = ex04
CFLAGS = -Wall -Wextra -Werror -std=c++11

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
OUTFILE = *.replace.txt

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(OUTFILE)

re: fclean all

.PHONY: all re clean fclean