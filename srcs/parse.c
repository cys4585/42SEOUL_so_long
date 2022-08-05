/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:34:55 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/05 13:51:16 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "fcntl.h"
#include "error.h"

static int	open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	check_error(SYSTEM_CALL, "open", (ssize_t)fd);
	return (fd);
}

static char	*init_empty_str(void)
{
	char	*str;

	str = malloc(1);
	check_error(MALLOC, "malloc", (ssize_t)str);
	*str = '\0';
	return (str);
}

static char	*make_map_str(int fd)
{
	char	*ret_gnl;
	char	*join;
	char	*temp;

	join = init_empty_str();
	while (1)
	{
		ret_gnl = get_next_line(fd);
		if (!ret_gnl)
			break ;
		if (*ret_gnl == '\n')
			print_error("There are not enough wall");
		temp = join;
		join = ft_strjoin(join, ret_gnl);
		check_error(LIBFT, "ft_strjoin", (ssize_t)join);
		ft_safe_free(ret_gnl);
		ft_safe_free(temp);
	}
	close(fd);
	return (join);
}

char	**parse(char *file)
{
	int		fd;
	char	*map_str;
	char	**map;

	fd = open_file(file);
	map_str = make_map_str(fd);
	map = ft_split(map_str, '\n');
	check_error(LIBFT, "ft_split", (ssize_t)map);
	ft_safe_free(map_str);
	return (map);
}
