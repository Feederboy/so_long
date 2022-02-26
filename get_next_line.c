/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:49:45 by matt              #+#    #+#             */
/*   Updated: 2022/02/16 19:22:12 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer;
	char	rtn[7000];
	int		n;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = 0;
	n = read(fd, &buffer, 1);
	while (n > 0)
	{
		if (buffer == '\n')
			break ;
		rtn[i++] = buffer;
		n = read(fd, &buffer, 1);
	}
	rtn[i] = 0;
	if (n <= 0 && i == 0)
		return (0);
	return (ft_strdup(rtn));
}
