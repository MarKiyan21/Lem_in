#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 15:56:10 by mkyianyt          #+#    #+#              #
#    Updated: 2017/06/21 16:06:01 by mkyianyt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC = associate_array.c check.c fill.c fill_continue.c find.c find_all_ways.c\
	  init.c lem_in.c read.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;1mBuilding archive babyyyy...wait...\033[0m"
	@make -C libft/
	@gcc $(FLAGS) -o $(NAME) -L libft/ -lft $(OBJ)
	@echo "\033[33;1mAbra Kadabra!!!\033[0m"

.c.o:
	@echo "\033[34;3mGetting funky with\033[0m $<"
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@echo "\033[31mRemoving lem-in...\033[0m"
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norme:
	norminette $(SRC)
