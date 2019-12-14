/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewarh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:56:42 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/13 23:27:35 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWARH_H
# define COREWARH_H

# define SUCCESS ft_printf("Success\n");
# define FAILURE ft_printf("failure\n");
# define IN ft_printf("in\n");
# define OUT ft_printf("out\n");

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <libft.h>
# include <op.h>

typedef struct	s_champion
{
	char	*name;
	int	number;
}		t_champion;

typedef struct s_global
{
	struct s_alloc	*global_allocs;
	struct s_alloc	*tempo_allocs;
	struct s_champion	*champions;
	int		champion_count;

}		t_global;

int	ft_check_cor_extension(char *potential_champion);
int	ft_count_champions(char **argv);
void	ft_create_champions(t_global *global_data, char **argv);
#endif
