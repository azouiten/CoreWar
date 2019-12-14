# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 17:52:15 by ohachim           #+#    #+#              #
#    Updated: 2019/12/13 23:27:57 by ohachim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

SRC_NAME = main.c \
	   ft_create_champions.c \
	   ft_count_champions.c \
	   ft_check_cor_extension.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS =-Iinclude -Ilibft/include

LDFLAGS = -Llibft

LDLIBS = -lft

NAME = corewar

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
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
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
