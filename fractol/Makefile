# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiego <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 16:01:49 by sdiego            #+#    #+#              #
#    Updated: 2019/10/31 16:01:50 by sdiego           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = ./src/main.c ./src/menu.c ./src/key2.c ./src/key3.c ./src/key.c ./src/cr_sierpinski.c ./src/cr_multibrot.c ./src/cr_multi_julia.c ./src/cr_tricorn.c ./src/cr_burning_ship.c ./src/print_err.c ./src/use.c ./src/check.c ./src/create_lists.c ./src/mini_lib2.c ./src/fractol.c ./src/cr_mandelbrot.c ./src/cr_julia.c ./src/draw.c ./src/color.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -o

INCLUDES = ./includes

HEADERS = $(INCLUDES)/errors.h $(INCLUDES)/fractol.h

LDLIBS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@make -C ./minilibx_macos/
	@gcc $(CFLAGS) $(NAME) $(OBJ) -I /usr/local/include -I$(INCLUDES) -L ./minilibx_macos/ $(LDLIBS)
	@echo "Compiling fractol"

.c.o:
	@gcc $(CFLAGS) -I./$(INCLUDES) -c $< -o $@

clean:
	@make clean -C ./minilibx_macos/
	@/bin/rm -f $(OBJ)
	@echo "Clear files"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Fclear files"

re: fclean all
