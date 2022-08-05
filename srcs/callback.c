/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:14:15 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/05 13:51:26 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "use_mlx.h"

static void	termintate(t_game_info *p_game_info)
{
	mlx_destroy_window(p_game_info->mlx_info.p_mlx, \
		p_game_info->mlx_info.p_win);
	exit(EXIT_SUCCESS);
}

int	on_destroy_callback(void *param)
{
	termintate((t_game_info *)param);
	return (0);
}

int	on_keydown_callback(int keycode, void *param)
{
	if (keycode == KEY_D || keycode == KEY_A \
		|| keycode == KEY_S || keycode == KEY_W)
		command_to_move_player(keycode, (t_game_info *)param);
	else if (keycode == KEY_ESC)
		termintate((t_game_info *)param);
	return (0);
}
