# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 15:56:17 by aziabkin          #+#    #+#              #
#    Updated: 2018/05/03 19:13:52 by aziabkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
LBF  = libft
SRCS = get_next_line.c
OFILES = $(SRCS:.c=.o)
FLAGS ?= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OFILES)
	make -C libft re
	gcc $(FLAGS) -o $(NAME) -I $(LBF) -L ./libft/ -lft $(OFILES)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< -I ./libft/

clean:
	rm -f $(OFILES)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
re: fclean all
