NAME = avm

SRCS = main.cpp \
Factory.cpp \
Lexer.cpp \
Parser.cpp \
Exception.cpp \
Executor.cpp \

OBJ = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ -std=c++11 $(CPPFLAGS) $(SRCS) -lncurses -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $<

