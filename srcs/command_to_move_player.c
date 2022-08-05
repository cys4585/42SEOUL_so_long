/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_to_move_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:41:04 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/05 13:51:28 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "use_mlx.h"
#include "stdio.h"

static void	predict_next_coord(int keycode, \
								t_coordinate *next, \
								t_coordinate *curr)
{
	if (keycode == KEY_D)
	{
		next->x = curr->x + 1;
		next->y = curr->y;
	}
	else if (keycode == KEY_A)
	{
		next->x = curr->x - 1;
		next->y = curr->y;
	}
	else if (keycode == KEY_S)
	{
		next->y = curr->y + 1;
		next->x = curr->x;
	}
	else
	{
		next->x = curr->x;
		next->y = curr->y - 1;
	}
}

static int	is_movable(int keycode, \
						t_game_info *p_game_info, \
						t_coordinate *next)
{
	predict_next_coord(keycode, next, &p_game_info->map_info.player_coord);
	if (p_game_info->map_info.map[next->y][next->x] == '1')
		return (0);
	if (p_game_info->map_info.map[next->y][next->x] == 'E' \
		&& p_game_info->map_info.cnt_collectible > 0)
		return (0);
	return (1);
}

static void	draw_moved_player(t_game_info *p_game_info, \
								t_coordinate *curr, \
								t_coordinate *next)
{
	t_mlx_info	mlx_info;
	char		**map;

	map = p_game_info->map_info.map;
	mlx_info = p_game_info->mlx_info;
	if (map[curr->y][curr->x] == 'C')
	{
		p_game_info->map_info.cnt_collectible--;
		map[curr->y][curr->x] = '0';
		mlx_put_image_to_window(mlx_info.p_mlx, mlx_info.p_win, \
			mlx_info.p_img_empty, (next->x * IMG_SIZE), (next->y * IMG_SIZE));
	}
	else if (map[curr->y][curr->x] == 'E' \
		&& p_game_info->map_info.cnt_collectible == 0)
	{
		mlx_destroy_window(mlx_info.p_mlx, mlx_info.p_win);
		printf("Game clear.\nThe total number of movements is %zu.\n", \
			p_game_info->map_info.cnt_movement);
		exit(EXIT_SUCCESS);
	}
	mlx_put_image_to_window(mlx_info.p_mlx, mlx_info.p_win, \
		mlx_info.p_img_empty, (curr->x * IMG_SIZE), (curr->y * IMG_SIZE));
	mlx_put_image_to_window(mlx_info.p_mlx, mlx_info.p_win, \
		mlx_info.p_img_player, (next->x * IMG_SIZE), (next->y * IMG_SIZE));
}

static void	move_player(t_game_info *p_game_info, \
						t_coordinate *curr, \
						t_coordinate *next)
{
	char	**map;

	printf("number of movements: %zu\n", ++(p_game_info->map_info.cnt_movement));
	map = p_game_info->map_info.map;
	map[curr->y][curr->x] = map[next->y][next->x];
	map[next->y][next->x] = 'P';
	draw_moved_player(p_game_info, curr, next);
	curr->x = next->x;
	curr->y = next->y;
}

void	command_to_move_player(int keycode, t_game_info *p_game_info)
{
	t_coordinate	next;

	if (is_movable(keycode, p_game_info, &next))
		move_player(p_game_info, &p_game_info->map_info.player_coord, &next);
}
