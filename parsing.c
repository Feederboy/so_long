/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:10:35 by maquentr          #+#    #+#             */
/*   Updated: 2022/02/26 16:38:00 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nb_row(int fd)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = "";
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		len++;
		free(tmp);
	}
	close(fd);
	return (len);
}

char	**fill_map(int fd, char **av)
{
	char	**res;
	int		len;
	int		i;
	char	*tmp;

	len = get_nb_row(fd);
	tmp = "";
	i = 0;
	res = NULL;
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		res[i] = tmp;
		i++;
	}
	close(fd);
	return (res);
}

int	map_null(int fd, char **av)
{
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
	{
		write(2, "map vide\n", 9);
		free(tmp);
		close(fd);
		exit(EXIT_FAILURE);
	}
	free(tmp);
	close(fd);
	return (0);
}

int	parsing_map(int fd, char **av, t_data *data)
{
	map_null(fd, av);
	data->map.map = fill_map(fd, av);
	if (check_rect_map(data) != 0 || check_walls(data) != 0
		|| check_tiles(data) == 1 || check_tiles(data) == 2)
	{
		write(2, "map must be rectangular, surrounded by walls ", 45);
		write(2, "and contain 1xE,P and nxC\n", 26);
		close(fd);
		free_map(data->map.map);
		exit (EXIT_FAILURE);
	}
	close(fd);
	return (0);
}
