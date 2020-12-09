# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 13:32:14 by ksalmi            #+#    #+#              #
#    Updated: 2019/12/14 17:26:58 by laskolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = new_main.c get_next_line/get_next_line.c param_check.c tetrimino_check.c \
	   list_to_array.c solve.c makelist.c arrange.c

INCLIB = libft/includes/

INCGET = get_next_line/

OBJECTS = $(subst .c,.o,$(SRCS))

FLAGS = -Wall -Wextra -Werror

.PHONY: all library clean fclean re

all: $(NAME)

library:
	make -C libft/

$(NAME): library
	gcc -c $(SRCS) $(FLAGS) -I $(INCLIB) -I $(INCGET)
	mv get_next_line.o get_next_line/
	gcc -o $(NAME) $(FLAGS) $(SRCS) -I $(INCLIB) -I $(INCGET) -L libft/ -lft

clean:
	/bin/rm -f $(OBJECTS)
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all
