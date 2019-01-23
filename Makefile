NAME = avm

SRCS = src/main.cpp \
src/Factory.cpp \
src/Lexer.cpp \
src/Parser.cpp \
src/Exception.cpp \
src/Executor.cpp \

OBJ = $(SRCS:.cpp=.o)

CPPFLAGS = -std=c++11 -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ $(CPPFLAGS) $(SRCS) -o $(NAME) -I inc

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#%.o: %.cpp:
#	clang++ $(CPPFLAGS) -c $< -o $@
