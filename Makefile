# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkumar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/25 16:29:16 by pkumar            #+#    #+#              #
#    Updated: 2018/06/24 15:58:57 by pkumar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = *.c

all: $(NAME)

.PHONY: clean fclean re

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I fillit.h

clean:
	/bin/rm -f $(OUT)

fclean:	clean
	/bin/rm -f $(NAME)

re: fclean all
