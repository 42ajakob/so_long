NAME	= so_long
HEADERS	= -I ./include -I ~/MLX42/include
LIBS	= ~/MLX42/build/libmlx42.a -ldl -pthread -lm -Iinclude -lglfw -L "/Users/ajakob/homebrew/Cellar/glfw/3.3.8/lib/" -framework Cocoa -framework OpenGL -framework IOKit
FLAGS	= -Wall -Wextra -Werror -Wunreachable-code -Ofast

SRCS	= $(shell find . -name "*.c")
OBJS	= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake ~/MLX42 -B ~/MLX42/build && make -C ~/MLX42/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf ~/MLX42/build

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx