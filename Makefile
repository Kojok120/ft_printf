# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 21:40:05 by kokamoto          #+#    #+#              #
#    Updated: 2024/06/05 21:40:06 by kokamoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCDIR = .
LIBDIR = libft
NAME = libftprintf.a

$(NAME): $(SRC) $(HDR) $(LIB)
	$(MAKE) -C $(LIBDIR)
	cp $(LIB) $(NAME)

$PLACEHOLDER$ : $(NAME)

SRC = $(SRCDIR)/ft_printf.c
HDR = $(SRCDIR)/ft_printf.h
LIB = $(LIBDIR)/libft.a

all: program

program: $(SRC) $(HDR) $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L$(LIBDIR) -lft

$(LIB):
	$(MAKE) -C $(LIBDIR)

clean:
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	rm -f program

re: fclean all

.PHONY: all clean fclean re