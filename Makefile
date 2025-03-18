RM = rm -f

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ircserv
SRC = main.cpp Server.cpp Client.cpp Channel.cpp Command.cpp Data.cpp Join.cpp Part.cpp Quit.cpp Parser.cpp Kick.cpp\
Mode.cpp Nick.cpp Topic.cpp Invite.cpp Register.cpp Registry.cpp User.cpp Privmsg.cpp List.cpp Msg.cpp Cap.cpp Who.cpp\

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
