NAME = avm

SRCS =  src/main.cpp \
        src/Factory.cpp \
        src/Lexer.cpp \
        src/Parser.cpp \
        src/Exception.cpp \
        src/Executor.cpp \

OBJ = $(SRCS:.cpp=.o)

CPPFLAGS = -std=c++11 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(CPPFLAGS) $(SRCS) -o $(NAME) -I inc

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	clang++ $(CPPFLAGS) -o $@ -c $<

.PHONY: all clean fclean re