# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 21:40:05 by kokamoto          #+#    #+#              #
#    Updated: 2024/07/09 19:23:15 by kokamoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCDIR = .
LIBDIR = libft

SRC = $(SRCDIR)/ft_printf.c
LIB = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIB)
	$(CC) $(CFLAGS) -I $(LIBDIR) -c $(SRC)
	ar rc $(NAME) ft_printf.o $(LIBDIR)/*.o

$(LIB):
	make -C $(LIBDIR)

clean:
	rm -f ft_printf.o
	make -C $(LIBDIR) fclean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all