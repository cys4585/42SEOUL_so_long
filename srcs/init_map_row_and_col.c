/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_row_and_col.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:42:53 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/05 13:51:19 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static void	init_row_and_col(t_map_info *p_map_info)
{
	size_t	i;

	i = 0;
	while (p_map_info->map[i])
		i++;
	p_map_info->row = i;
	p_map_info->col = ft_strlen(p_map_info->map[0]);
}

static void	init_cnt(t_map_info *p_map_info)
{
	p_map_info->cnt_collectible = 0;
	p_map_info->cnt_movement = 0;
}

static void	init_coordinate(t_map_info *p_map_info)
{
	p_map_info->player_coord.x = 0;
	p_map_info->player_coord.y = 0;
}

void	init_map_info(t_map_info *p_map_info)
{
	init_row_and_col(p_map_info);
	init_cnt(p_map_info);
	init_coordinate(p_map_info);
}
