NAME		:= so_long
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX		:= ./libs/MLX42
LIBFTPRINTF := ./libs/ft_printf

HEADERS		:= -I $(LIBMLX)/include/
LIBS		:= $(LIBMLX)/build/libmlx42.a ./libs/ft_printf/libftprintf.a -ldl -Iinclude -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
SRCS		:= $(shell find ./ -iname "*.c")
OBJS		:= ${SRCS:.c=.o}

all: libmlx $(NAME)

install:
	@git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX)

remove:
	@rm -rf $(LIBMLX)

libmlx:
	@make -C $(LIBFTPRINTF)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@make -C $(LIBFTPRINTF) clean
	@rm -f $(OBJS) && rm -rf $(LIBMLX)/build

fclean: clean
	@make -C $(LIBFTPRINTF) fclean
	@rm -f $(NAME)

re:
	@make fclean
	@make

.PHONY: re, all, clean, fclean, libmlx, install, remove