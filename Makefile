NAME=so_long

CC=clang #-g3#-fsanitize=address

IFLAGS=-Iminilibx-linux

LFLAGS=-Lminilibx-linux -lX11 -lXext -lmlx

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

#INC=pipex.h

SRC=checkers_moves.c \
	ft_split.c \
	ft_strdup.c \
	ft_utils.c \
	get_next_line.c \
	handles.c \
	main.c \
	map_check.c \
	move.c \
	parsing2.c \
	parsing.c \
	render.c \
	render_move2.c \
	render_move.c \
	utils_parsing.c \
	window.c \

OBJ=$(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $<

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
all: $(NAME)

#bonus:
#	@make	all	OBJ="$(OBJ)"

clean:
	$(RM) $(OBJ) pipex

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
