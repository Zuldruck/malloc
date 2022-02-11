##
## EPITECH PROJECT, 2021
## minishell1
## File description:
## Makefile
##

CC = gcc # -g3 -fsanitize=address

SRC = $(wildcard src/*.c) \

OBJ = $(SRC:.c=.o)

NAME = libmy_malloc.so

CPPFLAGS = -I./include

CFLAGS = -W -Wall -Wextra -Werror -fPIC

LDLIBS = -lmy

LDFLAGS = -L./lib/my

all: make_lib $(NAME)

make_lib:
	$(MAKE) -C lib/my

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(LDFLAGS) $(OBJ) $(LDLIBS)

clean:
	$(MAKE) -C lib/my clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME)

re: fclean all

debug: make_lib
	$(CC) -g -o $(NAME) $(LDFLAGS) $(SRC) $(CFLAGS) $(LDLIBS) $(CPPFLAGS)
