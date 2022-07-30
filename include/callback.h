/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:23:54 by youngcho          #+#    #+#             */
/*   Updated: 2022/07/30 15:38:33 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALLBACK_H
# define CALLBACK_H

# include "so_long.h"

void	predict_next_coordinate(int keycode, t_coordinate *player_coord);
int		is_movable(char **map, t_coordinate *coord, int nbr_collectible);
void	move_and_draw_player(t_game_info *game, char **map,
			t_coordinate *coord);
void	command_player_to_move(int keycode, void *param);

#endif