/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:06:14 by matt              #+#    #+#             */
/*   Updated: 2022/02/26 14:58:54 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_after_minimize(t_data *data)
{
	render_ground(data);
	render_walls(data);
	render_exit(data);
	render_collectibles(data);
	render_player(data);
	return (0);
}

void	ft_endgame(t_data *data)
{
	free_map(data->map.map);
	data->map.map = NULL;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	exit(EXIT_SUCCESS);
}

void	render_map(t_data *data, int direction)
{
	int	i;
	int	j;

	get_player_pos(data);
	i = data->map.playerposi;
	j = data->map.playerposj;
	if ((direction == UP && data->map.map[i - 1][j] == 'E') ||
		(direction == RIGHT && data->map.map[i][j + 1] == 'E') ||
		(direction == DOWN && data->map.map[i + 1][j] == 'E') ||
		(direction == LEFT && data->map.map[i][j - 1] == 'E'))
		ft_endgame(data);
	data->map.map[i][j] = '0';
	if (direction == UP)
		data->map.map[i - 1][j] = 'P';
	else if (direction == RIGHT)
		data->map.map[i][j + 1] = 'P';
	else if (direction == DOWN)
		data->map.map[i + 1][j] = 'P';
	else if (direction == LEFT)
		data->map.map[i][j - 1] = 'P';
}

void	render_background_on_player_pos(t_data *data, int i, int j)
{
	data->width = SIZE_IMG;
	data->height = SIZE_IMG;
	data->path = PATH_GROUND;
	data->img2 = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path, &data->width, &data->height);
	check_if_image_exists(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img2, j * SIZE_IMG, i * SIZE_IMG);
	mlx_destroy_image(data->mlx_ptr, data->img2);
}
