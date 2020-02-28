# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 07:27:29 by ohachim           #+#    #+#              #
#    Updated: 2020/02/27 08:02:11 by ohachim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_VM_PATH = VM/src

SRC_VM_NAME = main.c \
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
			  visu_init.c\
			  visu_print_handler.c\
			  visu_print_arena.c\
			  visu_print_stats.c

SRC_VM = $(addprefix $(SRC_VM_PATH)/,$(SRC_VM_NAME))

OBJ_VM_PATH = VM/obj

OBJ_VM_NAME = $(SRC_VM_NAME:.c=.o)

OBJ_VM = $(addprefix $(OBJ_VM_PATH)/,$(OBJ_VM_NAME))

CPPFLAGS_VM = -I VM/include -I VM/libft/include

LDFLAGS_VM = -L VM/libft

LDLIBS_VM = -lft -lcurses

NAME_VM = VM/corewar

DEPS_VM = VM/include/corewarh.h VM/include/op.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME_ASSEMBLER = 

NAME = $(NAME_VM) $(NAME_ASSEMBLER)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME_VM): $(OBJ_VM)
	@cd VM/libft ; make
	$(CC) $^ -o $@ $(LDFLAGS_VM) $(LDLIBS_VM)

$(OBJ_VM_PATH)/%.o: $(SRC_VM_PATH)/%.c $(DEPS_VM)
	@mkdir $(OBJ_VM_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS_VM) -o $@ -c $<

clean:
	@cd VM/libft; make clean
	@cd Assembler/libft; make clean
	@rm -vf $(OBJ_VM)
	@rmdir $(OBJ_VM_PATH) 2> /dev/null || true

fclean: clean
	@cd VM/libft; make fclean
	@cd Assembler/libft; make fclean
	@rm -vf $(NAME_VM) $(NAME_ASSEMBLER)

re: fclean all













































