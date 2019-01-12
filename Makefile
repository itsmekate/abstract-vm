NAME = avm

SRCS = IOperand.cpp


OBJ = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ $(CPPFLAGS) $(SRCS) -lncurses -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $<

