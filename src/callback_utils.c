/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:23:00 by youngcho          #+#    #+#             */
/*   Updated: 2022/07/30 15:29:52 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "callback.h"

void	predict_next_coordinate(int keycode, t_coordinate *player_coord)
{
	if (keycode == KEY_D)
	{
		player_coord->next_x = player_coord->curr_x + 1;
		player_coord->next_y = player_coord->curr_y;
	}
	else if (keycode == KEY_A)
	{
		player_coord->next_x = player_coord->curr_x - 1;
		player_coord->next_y = player_coord->curr_y;
	}
	else if (keycode == KEY_S)
	{
		player_coord->next_y = player_coord->curr_y + 1;
		player_coord->next_x = player_coord->curr_x;
	}
	else
	{
		player_coord->next_x = player_coord->curr_x;
		player_coord->next_y = player_coord->curr_y - 1;
	}
}

int	is_movable(char **map, t_coordinate *coord, int nbr_collectible)
{
	if (map[coord->next_y][coord->next_x] == '1')
		return (0);
	if (map[coord->next_y][coord->next_x] == 'E' && nbr_collectible > 0)
		return (0);
	return (1);
}

void	move_and_draw_player(t_game_info *game, char **map, t_coordinate *coord)
{
	map[coord->curr_y][coord->curr_x] = map[coord->next_y][coord->next_x];
	map[coord->next_y][coord->next_x] = 'P';
	printf("number of movements: %d\n", ++(game->map_info.nbr_movement));
	mlx_put_image_to_window(game->mlx, game->win, game->player.img, \
		(coord->next_x * game->player.width), \
		(coord->next_y * game->player.height));
	if (map[coord->curr_y][coord->curr_x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->empty.img, \
			(coord->curr_x * game->empty.width), \
			(coord->curr_y * game->empty.height));
	else if (map[coord->curr_y][coord->curr_x] == 'C')
	{
		game->map_info.nbr_collectible--;
		map[coord->curr_y][coord->curr_x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->empty.img, \
			(coord->curr_x * game->empty.width), \
			(coord->curr_y * game->empty.height));
	}
	else if (map[coord->curr_y][coord->curr_x] == 'E' \
		&& game->map_info.nbr_collectible == 0)
		terminate_clear(game);
	coord->curr_x = coord->next_x;
	coord->curr_y = coord->next_y;
}

void	command_player_to_move(int keycode, void *param)
{
	t_game_info		*game;
	char			**map;
	t_coordinate	*coord;

	game = (t_game_info *)param;
	map = game->map_info.map_table;
	coord = &game->map_info.player_coord;
	predict_next_coordinate(keycode, coord);
	if (is_movable(map, coord, game->map_info.nbr_collectible))
		move_and_draw_player(game, map, coord);
}
