/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:45:59 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/05 13:51:20 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include <stdlib.h>

void	print_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

void	check_error(t_error e, char *str, ssize_t ret)
{
	if (e == LIBFT && ret == 0)
	{
		ft_putstr_fd("Error :", 2);
		ft_putstr_fd(str, 2);
		exit(1);
	}
	else if (e == SYSTEM_CALL && ret == -1)
	{
		ft_putstr_fd("Error :", 2);
		ft_putstr_fd(str, 2);
		exit(1);
	}
	else if (e == MALLOC && ret == 0)
	{
		ft_putstr_fd("Error :", 2);
		ft_putstr_fd(str, 2);
		exit(1);
	}
}
