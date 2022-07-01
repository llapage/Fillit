NAME = fillit

BIN = main.o struct.o reader.o algo.o map.o

FLAGS = -Wall -Werror -Wextra

SRC = main.c src/struct.c src/reader.c src/algo.c src/map.c

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -c $(SRC) -I includes/ -I libft/
	gcc $(FLAGS) libft/libft.a $(BIN) -o $(NAME)

clean:
	rm -f $(BIN)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re : fclean all

.PHONY: all clean fclean re
