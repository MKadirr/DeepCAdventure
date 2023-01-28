

SRC = src/lib/*.c \
      src/host.c \

OBJ = $(SRC:.c=.o)

NAME = dcahost

all: $(NAME)

W_FLAG = -W -Wall -Wextra -g3 -Os

LAST_FLAG = -Werror -ansi -pedantic

$(NAME):
		gcc $(NAME) -I include -o $(NAME) -g -lm


val: $(NAME)
		valgrind ./$(NAME)

push: fclean
      git add .
	  echo git commit -m ""
	  echo push

clean:
		rm -f $(OBJ)

fclean: clean
        rm -f $(NAME)
re:		fclean all

.PHONY: all fclean clean re