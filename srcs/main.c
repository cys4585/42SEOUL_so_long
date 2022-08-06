/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:07:00 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/05 15:01:50 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception.h"
#include "init.h"
#include "libft.h"
#include "parse.h"
#include "so_long.h"
#include "use_mlx.h"

static void	free_map(t_map_info *p_map_info)
{
	size_t	i;

	i = 0;
	while (p_map_info->map[i])
	{
		ft_safe_free(p_map_info->map[i]);
		i++;
	}
	ft_safe_free(p_map_info->map);
}

int	main(int argc, char *argv[])
{
	t_game_info	game_info;

	check_file_name(argc, argv[1]);
	game_info.map_info.map = parse(argv[1]);
	init_map_info(&game_info.map_info);
	check_map(&game_info.map_info);
	init_mlx_info(&game_info);
	draw_map(&game_info);
	mlx_hook(game_info.mlx_info.p_win, ON_KEYDOWN, 0, \
		&on_keydown_callback, &game_info);
	mlx_hook(game_info.mlx_info.p_win, ON_DESTROY, 0, \
		&on_destroy_callback, &game_info);
	mlx_loop(game_info.mlx_info.p_mlx);
	free_map(&game_info.map_info);
	return (0);
}
