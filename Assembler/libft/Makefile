# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouiten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 00:49:39 by azouiten          #+#    #+#              #
#    Updated: 2019/12/15 15:48:31 by azouiten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

OBJ_PATH = obj

SRC_NAME = ft_atoi.c		\
		   ft_bzero.c		\
		   ft_isalnum.c		\
		   ft_isalpha.c		\
		   ft_isascii.c		\
		   ft_isdigit.c		\
		   ft_isprint.c		\
		   ft_itoa.c		\
		   ft_lstadd.c		\
		   ft_lstdel.c		\
		   ft_lstdelone.c	\
		   ft_lstiter.c		\
		   ft_lstjoin.c		\
		   ft_lstmap.c		\
		   ft_lstnew.c		\
		   ft_lstprint.c	\
		   ft_memalloc.c	\
		   ft_memccpy.c		\
		   ft_memchr.c		\
		   ft_memcmp.c		\
		   ft_memcpy.c		\
		   ft_memdel.c		\
		   ft_memmove.c		\
		   ft_memset.c		\
		   ft_putchar.c		\
		   ft_putchar_fd.c	\
		   ft_putendl.c		\
		   ft_putendl_fd.c	\
		   ft_putnbr.c		\
		   ft_putnbr_fd.c	\
		   ft_putstr.c		\
		   ft_putstr_fd.c	\
		   ft_replace.c		\
		   ft_strcat.c		\
		   ft_strchr.c		\
		   ft_strclr.c		\
		   ft_strcmp.c		\
		   ft_strcpy.c		\
		   ft_strdel.c		\
		   ft_strdup.c		\
		   ft_strequ.c		\
		   ft_striter.c		\
		   ft_striteri.c	\
		   ft_strjoin.c		\
		   ft_strlcat.c		\
		   ft_strlen.c		\
		   ft_strmap.c		\
		   ft_strmapi.c		\
		   ft_strncat.c		\
		   ft_strncmp.c		\
		   ft_strncpy.c		\
		   ft_strndup.c		\
		   ft_strnequ.c		\
		   ft_strnew.c		\
		   ft_strnstr.c		\
		   ft_strrchr.c		\
		   ft_strsplit.c	\
		   ft_strstr.c		\
		   ft_strsub.c		\
		   ft_strtrim.c		\
		   ft_tolower.c		\
		   ft_toupper.c		\
		   ft_words.c		\
		   get_next_line.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INCL = -Iinclude

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ) 
	ar rc $@ $^
	@ranlib $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(INCL) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

norme :
	@norminette $(SRC)
	@norminette include
