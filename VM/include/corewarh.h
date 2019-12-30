/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewarh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:56:42 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/30 16:06:56 by ohachim          ###   ########.fr       */
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
# include <string.h>
# include <libft.h>
# include "op.h"
# include <stdio.h> // Should remove.

enum	                e_errors
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

typedef struct			s_champion
{
    char			    *name;
    unsigned char		*byte_name;
    unsigned char		*comment;
    unsigned char		*exec_code;
    int			        number;
    int		        	validity;
    int                 starting_point;
    int			        fd;
    int                 argn;
    long long		    hex_code_size;
}						t_champion;

typedef union 			u_hexa
{
    unsigned char       buf[4];
    long long           value;
}                       t_hexa;
typedef union           u_reg
{
    unsigned char       reg_mem[REG_SIZE];
    int                 value; // TODO might change to int array instead of a union.
}                       t_reg;

typedef struct          s_process
{
    //int			program_counter; //  TODO Check this, possible change type to u_reg.
   	//int         *registries;
	int					current_op;
	int					bytes_to_next_op;
	int					cycles_till_op;
    int                 carry;
	int					last_live;
	struct s_process	*next;	
}                       t_process;

typedef struct			s_global
{
    struct s_champion	*champions;
    //struct s_process    *processes;
	struct s_champion	last_live_player;
    unsigned char       *arena;
    char                **error_buf;
	int				last_champion_index;
	int					number_of_checks;
    int                 valid_champions;
    int                 champion_count;
	int					cycle_since_start;
    int                 cycles_to_die;

}				t_global;

void                ft_fill_arena(t_global *global_data); // Creates the arena, transports the valid champions s code to their rightful place in the arena.
void                ft_prepare_arena(t_global *global_data); // Allocated unsigned char arena and fills counts the number of valid players, it with 0s, fixes the starting point of every champion.
int				    ft_dodge_bytes(t_global *global_data, int i, int bytes, int error_num); // Dodges 4 bytes by reading them.
void				ft_free_data(t_global *global_data); // Frees global_data allocs.
void				ft_gather_byte_code(t_global *global_data); // For now, it extracts name from the .cor byte_code.
void				ft_check_magic_headers(t_global *global_data, int i, int ret); // Checks for champions with invalid magic headers, and assigns 0 to their validity.
int				    ft_check_cor_extension(char *potential_champion); // Check if the files is an actual champion (has a .cor extension).
int				    ft_count_champions(char **argv); // Counts the number of champions given as arguments using the check_cor_extension fucntion.
void				ft_create_champions(t_global *global_data, char **argv); // Allocates to struct champion, and initializes it.
void				ft_fill_champions(char **argv, t_global *global_data); // Fill champions structure with their file names in the order demanded.
void				ft_manage_error(t_global *global_data, int error_num, int champion_index, int exit); // Prints error codes, and frees then exits if demanded.
#endif
