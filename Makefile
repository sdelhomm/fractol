# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 16:13:44 by sdelhomm          #+#    #+#              #
#    Updated: 2018/01/20 12:46:37 by sdelhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror -O3


SRC =	main.c \
		generate.c \
		fractale.c \
		events.c \
		hud.c \
		info.c \
		reset_fract.c \
		colors.c

OBJ =	main.o \
		generate.o \
		fractale.o \
		events.o \
		hud.o \
		info.o \
		reset_fract.o \
		colors.o

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@echo "\033[33;32m=== COMPILATION DE LA LIBFT ===\t\t\t\t[ ✓ ]"
	@gcc -o $(NAME) $(OBJ) $(FLAGS) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[33;32m=== CREATION DE L'EXECUTABLE \"$(NAME)\" ===\t\t[ ✓ ]"

%.o: %.c
	@gcc $(FLAGS) -I libft/ -c $< -o $@

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re