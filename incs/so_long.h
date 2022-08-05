/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 21:36:34 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/05 13:51:45 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

typedef struct s_coordinate {
	size_t	x;
	size_t	y;
}	t_coordinate;

typedef struct s_map_info
{
	char			**map;
	size_t			row;
	size_t			col;
	size_t			cnt_collectible;
	size_t			cnt_movement;
	t_coordinate	player_coord;

}	t_map_info;

typedef struct s_mlx_info
{
	void	*p_mlx;
	void	*p_win;
	void	*p_img_wall;
	void	*p_img_empty;
	void	*p_img_player;
	void	*p_img_collectible;
	void	*p_img_exit;
}	t_mlx_info;

typedef struct s_game_info
{
	t_mlx_info	mlx_info;
	t_map_info	map_info;
}	t_game_info;

#endif
