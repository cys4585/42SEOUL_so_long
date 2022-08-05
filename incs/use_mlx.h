/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:30:59 by youngcho          #+#    #+#             */
/*   Updated: 2022/08/05 13:51:44 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USE_MLX_H
# define USE_MLX_H

# include "so_long.h"
# include "mlx.h"

# define IMG_SIZE 32

# define ON_KEYDOWN 2
# define ON_DESTROY 17

# define KEY_D 2
# define KEY_A 0
# define KEY_S 1
# define KEY_W 13
# define KEY_ESC 53

void	init_mlx_info(t_game_info *p_game_info);
void	draw_map(t_game_info *p_game_info);
void	command_to_move_player(int keycode, t_game_info *p_game_info);
int		on_keydown_callback(int keydown, void *param);
int		on_destroy_callback(void *param);

#endif