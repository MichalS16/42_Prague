# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#              #
#    Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush-02

SRC		= main.c dict.c dict_parse.c convert.c convert_utils.c utils.c utils2.c

OBJECTS	= $(SRC:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
