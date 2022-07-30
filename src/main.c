/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:42:20 by youngcho          #+#    #+#             */
/*   Updated: 2022/07/30 16:31:53 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{	
	t_game_info	*game;
	
	game = (t_game_info *)malloc(sizeof(t_game_info));
	game->map_info.map_table = read_map_file(argv[argc - 1]);
	if (game->map_info.map_table == NULL)
		return (0);
	// valid check


	start_game(game);
	mlx_hook(game->win, ON_KEYDOWN, 0, &on_keydown_callback, game);
	mlx_hook(game->win, ON_DESTROY, 0, &on_destroy_callback, game);
	mlx_loop(game->mlx);
	return (0);
}