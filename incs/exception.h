/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:06:05 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/05 13:51:48 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_H
# define EXCEPTION_H

# include <stdlib.h>
# include "so_long.h"

typedef struct s_cnt
{
	size_t	p;
	size_t	e;
}	t_cnt;

typedef struct s_idx_of_rectangular
{
	size_t	col;
	size_t	row;
}	t_idx;

void	check_file_name(int argc, char *file);
void	check_map(t_map_info *p_map_info);
void	check_inner_and_count_characters(t_map_info *p_map_info);

#endif
