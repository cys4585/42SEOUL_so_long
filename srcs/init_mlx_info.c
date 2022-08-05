/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:29:29 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/05 13:51:18 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "use_mlx.h"

static void	*create_mlx_image(t_game_info *p_game_info, \
								char *file, int *w, int *h)
{
	return (mlx_xpm_file_to_image(p_game_info->mlx_info.p_mlx, \
		file, w, h));
}

void	init_mlx_info(t_game_info *p_game_info)
{
	int	w_tmp;
	int	h_tmp;

	p_game_info->mlx_info.p_mlx = mlx_init();
	p_game_info->mlx_info.p_win = mlx_new_window(p_game_info->mlx_info.p_mlx, \
		p_game_info->map_info.col * 32, p_game_info->map_info.row * 32, \
		"youngcho's so_long");
	p_game_info->mlx_info.p_img_wall = create_mlx_image(\
		p_game_info, "./assets/imgs/wall.xpm", &w_tmp, &h_tmp);
	p_game_info->mlx_info.p_img_empty = create_mlx_image(\
		p_game_info, "./assets/imgs/background.xpm", &w_tmp, &h_tmp);
	p_game_info->mlx_info.p_img_collectible = create_mlx_image(\
		p_game_info, "./assets/imgs/coin.xpm", &w_tmp, &h_tmp);
	p_game_info->mlx_info.p_img_player = create_mlx_image(\
		p_game_info, "./assets/imgs/player.xpm", &w_tmp, &h_tmp);
	p_game_info->mlx_info.p_img_exit = create_mlx_image(\
		p_game_info, "./assets/imgs/exit.xpm", &w_tmp, &h_tmp);
}
