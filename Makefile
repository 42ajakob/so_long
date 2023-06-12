NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ~/.brew/include/ -I $(LIBMLX)/include/
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -Iinclude -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
SRCS	:= $(shell find . -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

MLX42:
	@git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX)

rmMLX42:
	@rm -rf $(LIBMLX)

42HOMEBREW:
	@curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

rm42HOMEBREW:
	@rm -rf ~/.brew
	@rm -f ~/.brewconfig.zsh
	@echo "remove brew from .zshrc"

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
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) "

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, install, remove, MLX42, rmMLX42, 42HOMEBREW, rm42HOMEBREW, GLFW, rmGLFW, CMAKE, rmCMAKE