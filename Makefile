NAME = test

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = \
	finalize.c \
	get_next_line.c \
	map_push.c \
	parse.c \
	parse_config.c \
	parse_map.c \
	parse_line.c \
	parse_utils.c \
	strtrim.c \
	test_main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

