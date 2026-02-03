NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes/minilibx-linux

SRCS = fractol.c ./src/helpers.c ./src/helpers_1.c ./src/julia_mandelbrot.c ./src/string_to_double.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = includes/minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
