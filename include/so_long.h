/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:30:18 by youngcho          #+#    #+#             */
/*   Updated: 2022/07/29 19:28:41 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "mlx.h"
# include "libft.h"

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 100
# endif

# define ON_KEYDOWN 2

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

typedef struct	s_coordinate {
	int	x;
	int	y;
}	t_coordinate;

typedef struct	s_map_info {
	char			**map_table;
	t_coordinate	player_coord;
	int				nbr_collectible;
	int				nbr_movement;
}	t_map_info;

typedef struct	s_component {
	void	*img;
	int		width;
	int		height;
}	t_component;

typedef struct	s_game_info {
	t_map_info		map_info;
	void			*mlx;
	void			*win;
	t_component		empty;
	t_component		exit;
	t_component		collectible;
	t_component		player;
	t_component		wall;
}	t_game_info;

char	**read_map_file(char *file_path);
int	keydown_callback(int keycode, void *param);
void	init_to_game(t_game_info *game_info);

#endif