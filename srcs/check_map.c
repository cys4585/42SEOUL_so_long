/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:27:40 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/05 13:51:23 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "exception.h"
#include "libft.h"
#include "so_long.h"

static void	check_map_is_rectangular(t_map_info *p_map_info)
{
	size_t	row;

	row = 0;
	if (p_map_info->row < 3 || p_map_info->col < 3)
		print_error("There are not enough characters in rectangular!");
	while (row < p_map_info->row)
	{
		if (p_map_info->col != ft_strlen(p_map_info->map[row]))
			print_error("It is not rectangular!");
		row++;
	}
}

static void	check_edge_is_wall(t_map_info *p_map_info)
{
	size_t	col;
	size_t	row;

	col = 0;
	while (col < p_map_info->col)
	{
		if (p_map_info->map[0][col] != '1' || \
			p_map_info->map[p_map_info->row - 1][col] != '1')
			print_error("There are not enough wall");
		col++;
	}
	row = 0;
	while (row < p_map_info->row)
	{
		if (p_map_info->map[row][0] != '1' || \
			p_map_info->map[row][p_map_info->col - 1] != '1')
			print_error("There are not enough wall");
		row++;
	}
}

void	check_map(t_map_info *p_map_info)
{
	check_map_is_rectangular(p_map_info);
	check_edge_is_wall(p_map_info);
	check_inner_and_count_characters(p_map_info);
}
