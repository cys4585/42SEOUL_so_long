/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inner_and_count_characters.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:44:10 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/05 13:51:24 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "exception.h"
#include "so_long.h"
#include "libft.h"

static void	check_minimum_conditions(t_cnt *p_cnt, t_map_info *p_map_info)
{
	if (p_cnt->p != 1)
		print_error("Map must have one player");
	if (p_cnt->e == 0)
		print_error("Map must have at least one exit");
	if (p_map_info->cnt_collectible == 0)
		print_error("Map must have at least one collectible");
}

static void	check_and_count(t_map_info *p_map_info, t_cnt *p_cnt, \
							size_t y, size_t x)
{
	if (!ft_strchr("PEC01", p_map_info->map[y][x]))
		print_error("It is not correct characters");
	else if (p_map_info->map[y][x] == 'P')
	{
		p_cnt->p++;
		p_map_info->player_coord.x = x;
		p_map_info->player_coord.y = y;
	}
	else if (p_map_info->map[y][x] == 'E')
		p_cnt->e++;
	else if (p_map_info->map[y][x] == 'C')
		p_map_info->cnt_collectible++;
}

void	check_inner_and_count_characters(t_map_info *p_map_info)
{
	t_cnt	cnt;
	size_t	y;
	size_t	x;

	cnt.e = 0;
	cnt.p = 0;
	y = 1;
	while (y < p_map_info->row - 1)
	{
		x = 1;
		while (x < p_map_info->col - 1)
			check_and_count(p_map_info, &cnt, y, x++);
		y++;
	}
	check_minimum_conditions(&cnt, p_map_info);
}
