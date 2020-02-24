# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melalj <melalj@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 17:52:15 by ohachim           #+#    #+#              #
#    Updated: 2020/02/24 15:48:34 by melalj           ###   ########.fr        #
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
	   ft_fill_arena.c \
	   ft_create_initial_processes.c \
	   ft_battlegrounds.c \
	   ft_get_op.c \
	   op.c \
	   ft_get_bit_value.c \
	   ft_check_arg_validity.c \
	   ft_execute_hq.c \
	   ft_execute_live.c \
	   ft_get_ind_value.c \
	   ft_execute_load.c \
	   ft_execute_store.c \
	   ft_extract_argument_ind.c \
	   ft_execute_addition.c \
	   ft_execute_substraction.c \
	   ft_execute_or.c \
	   ft_execute_and.c \
	   ft_execute_xor.c \
	   ft_extract_argument_dir_long.c \
	   ft_get_arg.c \
	   ft_extract_argument_dir_short.c \
	   ft_execute_jump_if_zero.c \
	   ft_arena_cpy.c \
	   ft_get_arg_short.c \
	   ft_execute_store_index.c \
	   ft_execute_load_index.c \
	   ft_execute_fork.c \
	   ft_duplicate_process.c \
	   ft_execute_long_fork.c \
	   ft_execute_long_load.c \
	   ft_execute_long_load_index.c \
	   ft_execute_aff.c \
	   ft_print_arena.c \
	   ft_euclidean_mod.c \
	   ft_count_dodge_bytes.c \
	   ft_arg_size.c \
	   ft_check_registries.c \
	   ft_copy_arena.c\
	   print_arena.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS =-Iinclude -Ilibft/include

LDFLAGS = -Llibft

LDLIBS = -lft -lncurses

NAME = corewar

DEPS = include/corewarh.h include/op.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

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
