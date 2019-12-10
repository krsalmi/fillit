# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 18:00:22 by ksalmi            #+#    #+#              #
#    Updated: 2019/12/04 12:06:40 by ksalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl
SRCS = get_next_line.c main.c
OBJ = $(subst .c,.o,$(SRCS))

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	gcc -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	gcc -o $(NAME) main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	rm -f main.o get_next_line.o test_gnl
