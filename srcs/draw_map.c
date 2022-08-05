/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:02:27 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/05 13:51:27 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "use_mlx.h"

static void	put_img(t_game_info *p_game_info, void *p_img, int x, int y)
{
	mlx_put_image_to_window(p_game_info->mlx_info.p_mlx, \
		p_game_info->mlx_info.p_win, p_img, \
		x * IMG_SIZE, y * IMG_SIZE);
}

void	draw_map(t_game_info *p_game_info)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < p_game_info->map_info.row)
	{
		x = 0;
		while (x < p_game_info->map_info.col)
		{
			if (p_game_info->map_info.map[y][x] == '1')
				put_img(p_game_info, p_game_info->mlx_info.p_img_wall, x, y);
			else
				put_img(p_game_info, p_game_info->mlx_info.p_img_empty, x, y);
			if (p_game_info->map_info.map[y][x] == 'C')
				put_img(p_game_info, \
					p_game_info->mlx_info.p_img_collectible, x, y);
			else if (p_game_info->map_info.map[y][x] == 'E')
				put_img(p_game_info, p_game_info->mlx_info.p_img_exit, x, y);
			else if (p_game_info->map_info.map[y][x] == 'P')
				put_img(p_game_info, p_game_info->mlx_info.p_img_player, x, y);
			x++;
		}
		y++;
	}
}
