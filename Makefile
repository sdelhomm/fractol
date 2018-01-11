# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 16:13:44 by sdelhomm          #+#    #+#              #
#    Updated: 2018/01/09 11:39:06 by sdelhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror -O3


SRC =	main.c \
		generate.c \
		fractale.c \
		events.c

OBJ =	main.o \
		generate.o \
		fractale.o \
		events.o

all: $(NAME)

$(NAME):
	@make -C libft/
	@echo "\033[33;32m=== COMPILATION DE LA LIBFT ===\t\t\t\t[ ✓ ]"
	@gcc $(FLAGS) -I libft/ -c $(SRC)
	@echo "\033[33;32m=== CREATION DES OBJETS ===\t\t\t\t[ ✓ ]"
	@gcc -o $(NAME) $(OBJ) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[33;32m=== CREATION DE L'EXECUTABLE \"$(NAME)\" ===\t\t[ ✓ ]"

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re