##
## EPITECH PROJECT, 2021
## my_ls
## File description:
## Makefile
##

AR = ar

RM = rm -f

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CFLAGS = -W -Wall -Wextra -Werror -I./include

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) src $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
