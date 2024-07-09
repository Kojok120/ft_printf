# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 21:40:05 by kokamoto          #+#    #+#              #
#    Updated: 2024/07/09 19:40:00 by kokamoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#テスター用
# NAME = libftprintf.a
# CC = cc
# CFLAGS = -Wall -Werror -Wextra
# SRCDIR = .
# LIBDIR = libft

# SRC = $(SRCDIR)/ft_printf.c
# LIB = $(LIBDIR)/libft.a

# all: $(NAME)

# $(NAME): $(SRC) $(LIB)
# 	$(CC) $(CFLAGS) -I $(LIBDIR) -c $(SRC)
# 	ar rc $(NAME) ft_printf.o $(LIBDIR)/*.o

# $(LIB):
# 	make -C $(LIBDIR)

# clean:
# 	rm -f ft_printf.o
# 	make -C $(LIBDIR) fclean

# fclean: clean
# 	rm -f $(NAME)
# 	make -C $(LIBDIR) fclean

# re: fclean all




#個別コンパイル用
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