# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akliek <akliek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 17:01:47 by akliek            #+#    #+#              #
#    Updated: 2021/07/16 18:06:33 by akliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

HEADER = ft_printf.h

SRC = libft/*.c \
	*.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRC)
		ar rc $(NAME) *.o

bonus:
		$(CC) $(CFLAGS) $(SRC)
		ar rc $(NAME) *.o

clean:
		rm -rf *.o libft.h.gch

fclean: clean
		rm -rf $(NAME)

re:
		make fclean
		make all
