NAME	:= Minecraft
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./libs/MLX42

HEADERS	:= -I /Users/$(USER)/homebrew/include/ -I $(LIBMLX)/include/
LIBS	:= $(LIBMLX)/build/libmlx42.a ./libs/libft/libft.a -ldl -Iinclude -lglfw -L "/Users/$(USER)/homebrew/opt/glfw/lib/" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

MLX42:
	@git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX)

rmMLX42:
	@rm -rf $(LIBMLX)

HOMEBREW:
	@git clone https://github.com/Homebrew/brew ~/homebrew
	@eval "$(homebrew/bin/brew shellenv)"
	@brew update --force --quiet
	@chmod -R go-w "$(brew --prefix)/share/zsh"

rmHOMEBREW:
	@rm -rf ~/homebrew

GLFW:
	@brew install glfw

rmGLFW:
	@brew uninstall glfw

CMAKE:
	@brew install cmake

rmCMAKE:
	@brew uninstall cmake

install:
	${MLX42} && ${42HOMEBREW} && $(GLFW) && $(CMAKE)

remove:
	${rmMLX42} && ${rm42HOMEBREW}

libmlx:
	@cd libs/libft && make
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@cd libs/libft && make clean
	@rm -f $(OBJS) && rm -rf $(LIBMLX)/build

fclean: clean
	@cd libs/libft && make fclean
	@rm -f $(NAME)

re:
	@make fclean
	@make

.PHONY: re, all, clean, fclean, libmlx, install, remove, MLX42, rmMLX42, 42HOMEBREW, rm42HOMEBREW, GLFW, rmGLFW, CMAKE, rmCMAKE