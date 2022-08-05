/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:45:26 by jayoon            #+#    #+#             */
/*   Updated: 2022/08/05 13:51:49 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <unistd.h>

typedef enum e_error
{
	LIBFT,
	SYSTEM_CALL,
	MALLOC
}	t_error;

void	print_error(char *str);
void	check_error(t_error e, char *str, ssize_t ret);

#endif
