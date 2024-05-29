CFLAGS := -Wall -Wextra -Werror
LFLAGS := -L/usr/lib -lXext -lX11 -lm -lz
INCLUDE := -Iinclude -Ilibft/include -Iminilibx-linux
LIBFT := libft/libft.a
MINILIBX := minilibx-linux/libmlx_Linux.a
CFILES := src/main.c src/init.c src/utils.c src/hooks.c src/init_objects.c \
		  src/draw.c src/parse.c src/move.c src/check_map.c src/check_map_utils.c
OFILES := $(CFILES:.c=.o)
NAME := so_long

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OFILES)
	$(CC) $(OFILES) $(LIBFT) $(MINILIBX) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $^ -o $@ -g

$(LIBFT):
	@git submodule init
	@git submodule update
	@make -C libft

$(MINILIBX):
	@git submodule init
	@git submodule update
	-@make -C minilibx-linux

clean:
	@make -C libft clean
	@make -C minilibx-linux clean
	rm -f $(OFILES)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(MINILIBX)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
