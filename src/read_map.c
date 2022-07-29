/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:53:21 by youngcho          #+#    #+#             */
/*   Updated: 2022/07/29 18:55:57 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*strjoin_free_old_str(char const *old_str, char const *buf)
{
	char	*new_str;
	size_t	len_old;
	size_t	len_buf;

	if (old_str == NULL && buf == NULL)
		return (NULL);
	if (old_str == NULL)
		return (ft_strdup(buf));
	if (buf == NULL)
		return (ft_strdup(old_str));
	len_old = ft_strlen(old_str);
	len_buf = ft_strlen(buf);
	new_str = (char *)malloc(sizeof(char) * (len_old + len_buf + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, old_str, len_old + 1);
	ft_strlcpy(new_str + len_old, buf, len_buf + 1);
	free((void *)old_str);
	return (new_str);
}

char	**read_map_file(char *file_path)
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
	int		read_bytes;
	char	*str;
	char	**map;

	fd = open(file_path, O_RDONLY);
	str = NULL;
	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		str = strjoin_free_old_str(str, buf);
		if (str == NULL)
			return (NULL);
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}
