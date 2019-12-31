# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouiten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/06 12:38:23 by azouiten          #+#    #+#              #
#    Updated: 2019/12/29 18:39:41 by azouiten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

OBJ_PATH = obj

SRC_NAME = lexical_analysis.c \
		   op.c \
		   syntax_analysis.c 

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INCL = -Iinclude -Ilibft/include

INCLLFT = -Llibft

NAME = asm

CC = gcc

CFLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME):$(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(INCL) $(INCLLFT) -lft $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/random || true
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

clean:
	@make -C libft fclean
	@rm -vf $(OBJ)
	@rm -vrf $(OBJ_PATH) > /dev/random || true

fclean: clean
	@make -C libft fclean
	@rm -vf $(NAME)

re: fclean all
