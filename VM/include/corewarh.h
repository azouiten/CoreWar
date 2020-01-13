/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewarh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:56:42 by ohachim           #+#    #+#             */
/*   Updated: 2020/01/12 00:21:09 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWARH_H
# define COREWARH_H

# define SUCCESS ft_printf("Success\n");
# define FAILURE ft_printf("Failure\n");
# define IN ft_printf("In\n");
# define OUT ft_printf("Out\n");

# include <stdlib.h>
# include <unistd.h> 
# include <libft.h>
# include "op.h"
# include <stdio.h> // Should remove.

enum				e_errors
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
	TOTAL
};

typedef struct			s_op
{
	char			*name;
	int			argc;
	t_arg_type		tab[3];
	int			op_code;
	int			cost;
	char			*description;
	int			NA;
	int			NA0;
}				t_op;

typedef struct			s_champion
{
	char			*name;
	unsigned char		*byte_name;
	unsigned char		*comment;
	unsigned char		*exec_code;
	int			number;
	int		       	validity;
	int                 	starting_point;
	int			fd;
	int                 	argn;
	long long		hex_code_size;
}				t_champion;

typedef union 			u_hexa
{
	unsigned char       	buf[4];
	long long           	value;
}                       	t_hexa;

typedef struct          	s_process
{
	//int			program_counter; // Will keep up with where the process is in the arena.
	int			alive;
	int         		registries[REG_NUMBER]; // Will be used by champions, first registry contains the champion's index in its negative format for some reason, the others will be initialized with 0s.
	int			carriage_number; // Must be unique.
	int			carry; // Don't know its purpose yet, will be initialized with 0, some operations will be able to change its value.
	int			current_op; // Might change type later, will help us indentify the operation in which the process is currently sitting on.
	int			last_live_cycle; // The number of cycle where live was decalared last..
	int			cycles_till_op; // The number of cycles remaining till the current operation executes.
	int			process_cursor; // The value of where the process is sitting; might be referring to the PC (Program Counter).
	int			bytes_to_next_op; // The number of bytes needed to be crossed to get to the next operation.
	struct s_process	*next; // Processes start with the champion with the highest index, newborn processes get added last probably.	
}                       	t_process;

typedef struct			s_global
{
	struct s_champion	*champions; // The champions, some of them might not be valid, might duplicate this one with only the valid champions.
	struct s_process	*processes; // A process will help us execute the champions's code, it will be places at the beginning of every champions's code in the arena.
	struct s_champion	last_live_player; // The player who last declared it was alive, will be initialized with the player with the highest index.
	unsigned char		*arena; // The chunk of memory will the champions's code will be executed.
	char			**error_buf; // An array where error messages are stored.
	//	int			last_champion_index; // The bigest index with a valid champion in global.champions.
	int			champion_count; // The number of champions given as arguments, checks for the .cor extension to choose what's a champion.
	int			valid_champions; // Counts the number of champions who survived the error checks.
	int			cycle_since_start; // How many cycles past since beginning of the game. Still don't know where this will be usefull.
	int			number_lives_declared; // Keeps count of how many lives delcared before the end of a cycle_to_die.
	int			cycles_to_die; // The value of the current number of cycles before a check. will be initialized with CYCLES_TO_DIE.
	int			number_of_checks; // How many checks done so far, a check is done after every cycles_to_die, resets to 0 every time we decrement cycles_to_die.

}				t_global;
t_op	op_tab[17];

int				ft_get_bit_value(int number, int number_bits, int position);
void				ft_create_initial_processes(t_global *global_data); // Created initial processes and initalizes their content.
void				ft_fill_arena(t_global *global_data); // Creates the arena, transports the valid champions s code to their rightful place in the arena.
void				ft_prepare_arena(t_global *global_data); // Allocated unsigned char arena and fills counts the number of valid players, it with 0s, fixes the starting point of every champion.
int				ft_dodge_bytes(t_global *global_data, int i, int bytes, int error_num); // Dodges 4 bytes by reading them.
void				ft_free_data(t_global *global_data); // Frees global_data allocs.
void				ft_gather_byte_code(t_global *global_data); // For now, it extracts name from the .cor byte_code.
void				ft_check_magic_headers(t_global *global_data, int i, int ret); // Checks for champions with invalid magic headers, and assigns 0 to their validity.
int				ft_check_cor_extension(char *potential_champion); // Check if the files is an actual champion (has a .cor extension).
int				ft_count_champions(char **argv); // Counts the number of champions given as arguments using the check_cor_extension fucntion.
void				ft_create_champions(t_global *global_data, char **argv); // Allocates to struct champion, and initializes it.
void				ft_fill_champions(char **argv, t_global *global_data); // Fill champions structure with their file names in the order demanded.
void				ft_manage_error(t_global *global_data, int error_num, int champion_index, int exit); // Prints error codes, and frees then exits if demanded.
void				ft_battlegrounds(t_global *global_data);
void				ft_get_op(t_global *global_data);
#endif
