/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:15:58 by matt              #+#    #+#             */
/*   Updated: 2022/02/26 14:55:07 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_if_endgame(t_data *data, int i, int j, int direction)
{
	if (direction == UP)
	{
		if (data->map.map[i - 1][j] == 'E' && check_collec_left(data) == 0)
			return (1);
	}
	else if (direction == RIGHT)
	{
		if (data->map.map[i][j + 1] == 'E' && check_collec_left(data) == 0)
			return (1);
	}
	else if (direction == DOWN)
	{
		if (data->map.map[i + 1][j] == 'E' && check_collec_left(data) == 0)
			return (1);
	}
	else if (direction == LEFT)
	{
		if (data->map.map[i][j - 1] == 'E' && check_collec_left(data) == 0)
			return (1);
	}
	return (0);
}

int	ft_check_move_possible(t_data *data, int i, int j, int direction)
{
	if (ft_check_if_endgame(data, i, j, direction) == 1)
		return (1);
	if (direction == UP)
	{
		if (data->map.map[i - 1][j] == '1' || data->map.map[i - 1][j] == 'E')
			return (0);
	}
	else if (direction == RIGHT)
	{
		if (data->map.map[i][j + 1] == '1' || data->map.map[i][j + 1] == 'E')
			return (0);
	}
	else if (direction == DOWN)
	{
		if (data->map.map[i + 1][j] == '1' || data->map.map[i + 1][j] == 'E')
			return (0);
	}
	else if (direction == LEFT)
	{
		if (data->map.map[i][j - 1] == '1' || data->map.map[i][j - 1] == 'E')
			return (0);
	}
	return (1);
}

int	check_collec_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->map.playerposi = i;
				data->map.playerposj = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
