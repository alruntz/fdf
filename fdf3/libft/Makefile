# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alruntz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:44:41 by alruntz           #+#    #+#              #
#    Updated: 2018/01/22 14:50:21 by alruntz     ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  $(addsuffix .c,ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap ft_strlen ft_strmapi ft_strcmp ft_strequ ft_strncmp ft_strnequ ft_strsub ft_strjoin ft_putchar ft_putstr ft_strtrim  ft_strsplit ft_itoa ft_putendl ft_putnbr ft_strcpy ft_strncpy ft_strstr ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isprint ft_isascii ft_strcat ft_strncat ft_strdup ft_tolower ft_toupper ft_strnstr ft_strchr ft_strlcat ft_strrchr ft_memset ft_bzero ft_memcpy ft_memccpy ft_memchr ft_memcmp ft_memmove ft_putchar_fd ft_putendl_fd ft_putstr_fd ft_putnbr_fd ft_lstadd ft_lstdel ft_lstiter ft_lstmap ft_lstnew ft_lstdelone ft_lstlink ft_swap ft_match ft_nmatch ft_printbits ft_read_file ft_merge_str ft_get_charstr ft_strlen2d ft_print_color)

OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) -I $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
