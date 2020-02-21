/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewarh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:56:42 by ohachim           #+#    #+#             */
/*   Updated: 2020/02/19 00:01:10 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWARH_H
# define COREWARH_H

# define DEBUG 0

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>
# include "op.h"

enum					e_operations
{
	ZERO,
	LIVE,
	LOAD,
	STORE,
	ADDITION,
	SUBSTRACTION,
	AND,
	OR,
	XOR,
	JUMP_IF_ZERO,
	LOAD_INDEX,
	STORE_INDEX,
	FORK,
	LONG_LOAD,
	LONG_LOAD_INDEX,
	LONG_FORK,
	AFF,
	NIL
};

enum					e_errors
{
	ZERO_CHAMPION,
	TOO_MANY_PLAYERS,
	MALLOC_FAIL,
	OPEN_FAIL,
	READ_FAIL,
	MAGIC_HEADER_FAIL,
	DATA_LACK,
	EXEC_CODE_SIZE_FAIL,
	EXEC_CODE_SIZE_ZERO,
	EXEC_CODE_SIZE_WRONG,
	ZERO_VALID_CHAMPION,
	BIG_CHAMP,
	TOTAL
};

typedef struct			s_op
{
	char				*name;
	int					argc;
	t_arg_type			tab[3];
	int					op_code;
	int					cost;
	char				*description;
	int					arguments;
	int					t_dir_size;
}						t_op;

typedef struct			s_champion
{
	char				*name;
	unsigned char		*byte_name;
	unsigned char		*comment;
	unsigned char		*exec_code;
	int					number;
	int					validity;
	int					starting_point;
	int					fd;
	int					argn;
	long long			hex_code_size;
}						t_champion;

typedef struct			s_aff
{
	int					value;
	struct s_aff		*next;
}						t_aff;

typedef union			u_hexa
{
	unsigned char		buf[4];
	int					value;
	short int			short_value;
}						t_hexa;

typedef struct			s_process
{
	int					alive;
	int					registries[REG_NUMBER];
	int					carriage_number;
	int					carry;
	int					current_op;
	int					last_live_cycle;
	int					live_declared;
	int					cycles_till_op;
	int					process_cursor;
	int					bytes_to_next_op;
	char				arg[3];
	struct s_process	*next;
}						t_process;

typedef struct			s_global
{
	struct s_champion	*champions;
	struct s_process	*processes;
	struct s_champion	last_live_player;
	struct s_aff		*affs;
	unsigned char		*arena;
	unsigned char		*arena_dump;
	int					print;
	char				**error_buf;
	int					champion_count;
	int					valid_champions;
	int					cycle_since_start;
	int					number_lives_declared;
	int					cycles_to_die;
	int					number_of_checks;
	int					all_time_cycles;
	int					dump_cycle;
}						t_global;

t_op					g_op_tab[17];

char					ft_get_bit_value(unsigned char number, int number_bits,
						int position);
void					ft_create_initial_processes(t_global *global_data);
void					ft_fill_arena(t_global *global_data);
void					ft_prepare_arena(t_global *global_data);
int						ft_dodge_bytes(t_global *global_data, int i, int bytes,
						int error_num);
void					ft_free_data(t_global *global_data);
void					ft_gather_byte_code(t_global *global_data);
void					ft_check_magic_headers(t_global *global_data, int i,
						int ret);
int						ft_check_cor_extension(char *potential_champion);
int						ft_count_champions(char **argv);
void					ft_create_champions(t_global *global_data,
						char **argv);
void					ft_fill_champions(char **argv, t_global *global_data);
void					ft_manage_error(t_global *global_data, int error_num,
						int champion_index, int exit);
void					ft_battlegrounds(t_global *global_data, int after_life);
void					ft_get_op(t_global *global_data,
						t_process *temp_process);
int						ft_check_arg_validity(int arg, int arg_num,
						int current_op_index);
void					ft_execute_hq(t_process **process,
						t_global *global_data);
void					ft_execute_live(t_process **process,
						t_global *global_data);
int						ft_get_ind_value(t_global *global_data, int adress);
void					ft_execute_load(t_process **process,
						t_global *global_data);
void					ft_execute_store(t_process **process,
						t_global *global_data);
int						ft_extract_argument_ind(t_global *global_data,
						t_process **process, int byte_distance);
void					ft_execute_addition(t_process **process,
						t_global *global_data);
void					ft_execute_substraction(t_process **process,
						t_global *global_data);
void					ft_execute_or(t_process **process,
						t_global *global_data);
void					ft_execute_xor(t_process **process,
						t_global *global_data);
void					ft_execute_and(t_process **process,
						t_global *global_data);
int						ft_extract_argument_dir_long(t_global *global_data,
						t_process **process, int byte_distance);
int						ft_get_arg(t_process **process, t_global *global_data,
						int *dodge, int arg_index);
int						ft_extract_argument_dir_short(t_global *global_data,
						t_process **process, int byte_distance);
void					ft_execute_jump_if_zero(t_process **process,
						t_global *global_data);
void					ft_arena_cpy(t_global *global_data, int cpy_to,
						int to_cpy);
int						ft_get_arg_short(t_process **process,
						t_global *global_data, int *dodge, int arg_index);
void					ft_execute_store_index(t_process **process,
						t_global *global_data);
void					ft_execute_load_index(t_process **process,
						t_global *global_data);
void					ft_execute_fork(t_process **process,
						t_global *global_data);
t_process				*ft_duplicate_process(t_process *process, int adress,
						t_global *global_data);
void					ft_execute_long_fork(t_process **process,
						t_global *global_data);
void					ft_execute_long_load(t_process **process,
						t_global *global_data);
void					ft_execute_long_load_index(t_process **process,
						t_global *global_data);
void					ft_execute_aff(t_process **process,
						t_global *global_data);
void					ft_copy_arena(t_global *global_data);
void					ft_print_arena(t_global *global_data, int xs);
int						ft_euclidean_mod(int a, int b);
int						ft_count_dodge_bytes(t_global *global_data,
						t_process **process, int fail, int arg_num);
int						ft_arg_size(int arg, int current_op_index);
int						ft_check_registries(t_process **process, int reg_index,
						int arg_num, t_global *global_data);
void					ft_print_affs(t_global global_data);

#endif
