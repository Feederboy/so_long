/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:54:22 by matt              #+#    #+#             */
/*   Updated: 2022/02/26 14:58:09 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_map_extension(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (av[len - 1] != 'r' || av[len - 2] != 'e' || av[len - 3] != 'b')
		return (1);
	return (0);
}

int	check_map(int fd, char *av)
{
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Cannot open file\n", 17);
		return (1);
	}
	if (check_map_extension(av))
	{
		write(2, "Error: wrong map extension, <*.ber> required\n", 46);
		return (1);
	}
	close(fd);
	return (0);
}
