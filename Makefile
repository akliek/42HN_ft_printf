# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akliek <akliek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 17:01:47 by akliek            #+#    #+#              #
#    Updated: 2021/10/11 11:06:06 by akliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

SRC = ft_printf.c	\
	conversions.c	\
	printnum.c	\
	printstr.c	\
	printhex.c	\
	printchar.c	\
	libft/ft_isdigit.c	\
	libft/ft_itoa.c	\
	libft/ft_putstr_fd.c	\
	libft/ft_strchr.c	\
	libft/ft_strdup.c	\
	libft/ft_strlen.c	\
	libft/ft_strncmp.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRC)
		ar rc $(NAME) *.o

bonus:
		$(CC) $(CFLAGS) $(SRC)
		ar rc $(NAME) *.o

clean:
		rm -rf *.o

fclean: clean
		rm -rf $(NAME)

re:
		make fclean
		make all
