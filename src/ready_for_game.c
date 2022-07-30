/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_for_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:03:33 by youngcho          #+#    #+#             */
/*   Updated: 2022/07/30 16:30:43 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game_info *game, t_component component, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, component.img, \
		x * component.width, y * component.height);
}

void	put_img_and_cnt_collectible(t_game_info *game, int x, int y)
{
	put_img(game, game->collectible, x, y);
	game->map_info.nbr_collectible++;
}

void	put_img_and_set_player_coordinate(t_game_info *game, int x, int y)
{
	put_img(game, game->player, x, y);
	game->map_info.player_coord.curr_x = x;
	game->map_info.player_coord.curr_y = y;
}

void	set_map_info_and_draw_map(t_game_info *game)
{
	int	x;
	int	y;

	y = 0;
	game->map_info.nbr_collectible = 0;
	game->map_info.nbr_movement = 0;
	while (game->map_info.map_table[y])
	{
		x = 0;
		while (game->map_info.map_table[y][x])
		{
			if (game->map_info.map_table[y][x] == '1')
				put_img(game, game->wall, x, y);
			else if (game->map_info.map_table[y][x] == '0')
				put_img(game, game->empty, x, y);
			else if (game->map_info.map_table[y][x] == 'C')
				put_img_and_cnt_collectible(game, x, y);
			else if (game->map_info.map_table[y][x] == 'E')
				put_img(game, game->exit, x, y);
			else if (game->map_info.map_table[y][x] == 'P')
				put_img_and_set_player_coordinate(game, x, y);
			x++;
		}
		y++;
	}
}

void	start_game(t_game_info *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 640, 640, "test");
	game->empty.img = mlx_xpm_file_to_image(\
		game->mlx, "./asset/img/empty.xpm", \
		&(game->empty.width), &(game->empty.height));
	game->exit.img = mlx_xpm_file_to_image(\
		game->mlx, "./asset/img/exit.xpm", \
		&(game->exit.width), &(game->exit.height));
	game->collectible.img = mlx_xpm_file_to_image(\
		game->mlx, "./asset/img/item.xpm", \
		&(game->collectible.width), &(game->collectible.height));
	game->player.img = mlx_xpm_file_to_image(\
		game->mlx, "./asset/img/player.xpm", \
		&(game->player.width), &(game->player.height));
	game->wall.img = mlx_xpm_file_to_image(\
		game->mlx, "./asset/img/wall.xpm", \
		&(game->wall.width), &(game->wall.height));
	set_map_info_and_draw_map(game);
}
