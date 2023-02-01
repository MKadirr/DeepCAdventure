SRC_LIB = src/lib/Board.c \
		  src/lib/Player.c \



OBJ = $(SRC:.c=.o) \
	  $(SRC_LIB:.c=.o) \

NAME_H = host
SRC_H = src/host/dca_host.c

NAME_C = client
SRC_C = src/client.c

all: 
	$(NAME)

W_FLAG = -W -Wall -Wextra -g3 -Os

W_REC_FLAG = -lws2_32

LAST_FLAG = -Werror -ansi -pedantic 

$(NAME): host
	client

host:
	gcc $(SRC_H) $(SRC_LIB) -I include -o $(NAME_H) -g -lm $(W_FLAG) $(W_REC_FLAG)

client:
	gcc $(SRC_C) $(SRC_LIB) -I include -o $(NAME_C) -g -lm $(W_FLAG) $(W_REC_FLAG)

push:
	fclean
	git add .
	echo git commit -m ""
	echo push

clean:
	rm -f $(OBJ)

fclean: 
	clean;
	rm -f $(NAME)

re:		
	fclean all

.PHONY: all fclean clean re