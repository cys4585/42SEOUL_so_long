/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:08:40 by youngcho          #+#    #+#             */
/*   Updated: 2022/07/30 14:54:33 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	terminate_clear(t_game_info *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("Game clear.\nThe total number of movements is %d.\n", \
		game->map_info.nbr_movement);
	exit(EXIT_SUCCESS);
}

void	terminate_command(t_game_info *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

void	terminate_failure(t_game_info *game, char *err_msg)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("%s\n", err_msg);
	exit(EXIT_FAILURE);
}
