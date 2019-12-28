# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 17:52:15 by ohachim           #+#    #+#              #
#    Updated: 2019/12/26 18:33:33 by ohachim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

SRC_NAME = main.c \
	   ft_create_champions.c \
	   ft_count_champions.c \
	   ft_check_cor_extension.c \
	   ft_check_magic_headers.c \
	   ft_gather_byte_code.c \
	   ft_free_data.c \
	   ft_dodge_bytes.c \
	   ft_fill_champions.c \
	   ft_manage_error.c \
	   ft_prepare_arena.c \
	   ft_fill_arena.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS =-Iinclude -Ilibft/include

LDFLAGS = -Llibft

LDLIBS = -lft

NAME = corewar

DEPS = include/corewarh.h

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME) #visu
#*************************************#
#VISUALISATOR RULES		      #
#visu:                                #
#	@cd Lem_vis ; make            #
#visur:                               #
#	@cd Lem_vis ; make re         #
#visuc:                               #
#	@cd Lem_vis ; make clean      #
#visufc:                              #
#	@cd Lem_vis ; make fclean     #
#*************************************#

$(NAME): $(OBJ)
	@cd libft ; make
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS) -g

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -vf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C libft fclean
	@rm -vf $(NAME)

re: fclean all
