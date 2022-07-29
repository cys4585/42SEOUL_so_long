/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:42:20 by youngcho          #+#    #+#             */
/*   Updated: 2022/07/29 19:28:09 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{	
	t_game_info	*game_info;
	
	game_info = (t_game_info *)malloc(sizeof(t_game_info));
	// read_map
	game_info->map_info.map_table = read_map_file(argv[argc - 1]);
	if (game_info->map_info.map_table == NULL)
		return (0);
	
	// valid check


	init_to_game(game_info);
	mlx_hook(game_info->win, ON_KEYDOWN, 0, &keydown_callback, game_info);
	mlx_loop(game_info->mlx);
	return (0);
}