NAME	:= Minecraft
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./libs/MLX42

HEADERS	:= -I /Users/$(USER)/homebrew/include/ -I $(LIBMLX)/include/
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -Iinclude -lglfw -L "/Users/$(USER)/homebrew/opt/glfw/lib/" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
SRCS	:= $(shell find ./ -iname "*.c")
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

rm42HOMEBREW:
	@brew || rm -rf ~/homebrew

GLFW:
	@brew list glfw || brew install glfw

rmGLFW:
	@brew list glfw || brew uninstall glfw

CMAKE:
	@brew list cmake || brew install cmake

rmCMAKE:
	@brew list cmake || brew uninstall cmake

install:
	${MLX42} && ${42HOMEBREW} && $(GLFW) && $(CMAKE)

remove:
	${rmMLX42} && ${rm42HOMEBREW}

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) "

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS) && rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re:
	@make fclean
	@make

.PHONY: re, all, clean, fclean, libmlx, install, remove, MLX42, rmMLX42, 42HOMEBREW, rm42HOMEBREW, GLFW, rmGLFW, CMAKE, rmCMAKE