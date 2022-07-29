/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:56:24 by youngcho          #+#    #+#             */
/*   Updated: 2022/07/29 19:28:41 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keydown_callback(int keycode, void *param)
{
	t_game_info	*game_info;
	int			curr_x;
	int			curr_y;
	int			next_x;
	int			next_y;
	
	game_info = (t_game_info *)param;
	curr_x = game_info->map_info.player_coord.x;
	curr_y = game_info->map_info.player_coord.y;
	next_x = 0;
	next_y = 0;
	if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_S || keycode == KEY_W)
	{
		if (keycode == KEY_D)
		{
			next_x = curr_x + 1;
			next_y = curr_y;
		}
		else if (keycode == KEY_A)
		{
			next_x = curr_x - 1;		
			next_y = curr_y;
		}
		else if (keycode == KEY_S)
		{
			next_x = curr_x;
			next_y = curr_y + 1;
		}
		else if (keycode == KEY_W)
		{
			next_x = curr_x;
			next_y = curr_y - 1;		
		}
		if (game_info->map_info.map_table[next_y][next_x] != '1')
		{
			game_info->map_info.map_table[curr_y][curr_x] = game_info->map_info.map_table[next_y][next_x];
			game_info->map_info.map_table[next_y][next_x] = 'P';
			mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->player.img, next_x * game_info->player.width, next_y * game_info->player.height);
			if (game_info->map_info.map_table[curr_y][curr_x] == '0')
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->empty.img, curr_x * game_info->empty.width, curr_y * game_info->empty.height);
			else if (game_info->map_info.map_table[curr_y][curr_x] == 'C')
			{
				game_info->map_info.nbr_collectible--;
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->empty.img, curr_x * game_info->empty.width, curr_y * game_info->empty.height);
			}
			else if (game_info->map_info.map_table[curr_y][curr_x] == 'E' && game_info->map_info.nbr_collectible == 0)
			{
				mlx_destroy_window(game_info->mlx, game_info->win);
			}
			game_info->map_info.player_coord.x = next_x;
			game_info->map_info.player_coord.y = next_y;
			printf("%d\n", ++(game_info->map_info.nbr_movement));
		}
	}
	return (0);
}