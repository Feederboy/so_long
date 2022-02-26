/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:52:17 by matt              #+#    #+#             */
/*   Updated: 2022/02/26 15:00:10 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	get_char_tile(char m, t_data *data)
{
	if (m == 'C')
		data->map.c += 1;
	else if (m == 'P')
		data->map.p += 1;
	else if (m == 'E')
		data->map.e += 1;
}

int	check_tiles(t_data *data)
{
	int	i;
	int	j;

	data->map.c = 0;
	data->map.p = 0;
	data->map.e = 0;
	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (ft_strchr("ECP", data->map.map[i][j]))
				get_char_tile(data->map.map[i][j], data);
			if (!ft_strchr("ECP01", data->map.map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	if (data->map.c == 0 || data->map.p != 1 || data->map.e != 1)
		return (2);
	return (0);
}

int	check_rect_map(t_data *data)
{
	int	i;
	int	j;

	data->map.row = ft_size_row2(data->map.map, 0);
	data->map.col = ft_size_col2(data->map.map, 0);
	i = 0;
	while (data->map.map[i])
	{
		if (ft_size_row2(data->map.map, i) != data->map.row)
			return (1);
		j = 0;
		while (data->map.map[i][j])
		{
			if (ft_size_col2(data->map.map, j) != data->map.col)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_walls(t_data *data)
{
	int	i;
	int	j;

	data->map.wallsi = ft_size_row(data->map.map);
	data->map.wallsj = ft_size_col(data->map.map[0]);
	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if ((i == 0 || i == (data->map.wallsi - 1))
				&& data->map.map[i][j] != '1')
				return (1);
			if ((j == 0 || j == (data->map.wallsj - 1))
				&& data->map.map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
