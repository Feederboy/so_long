/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:56:00 by matt              #+#    #+#             */
/*   Updated: 2022/02/26 16:56:49 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_ground(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->height = SIZE_IMG;
	data->width = SIZE_IMG;
	data->path2 = PATH_GROUND;
	data->img2 = mlx_xpm_file_to_image(data->mlx_ptr, data->path2,
			&data->width, &data->height);
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img2, j * SIZE_IMG, i * SIZE_IMG);
		}
	}
	mlx_destroy_image(data->mlx_ptr, data->img2);
}

void	render_walls(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->height = SIZE_IMG;
	data->width = SIZE_IMG;
	data->path1 = PATH_WALL;
	data->img1 = mlx_xpm_file_to_image(data->mlx_ptr, data->path1,
			&data->width, &data->height);
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img1, j * SIZE_IMG, i * SIZE_IMG);
		}
	}
	mlx_destroy_image(data->mlx_ptr, data->img1);
}

void	render_collectibles(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->height = SIZE_IMG;
	data->width = SIZE_IMG;
	data->path1 = PATH_COLLEC;
	data->img1 = mlx_xpm_file_to_image(data->mlx_ptr, data->path1,
			&data->width, &data->height);
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img1, j * SIZE_IMG, i * SIZE_IMG);
		}
	}
	mlx_destroy_image(data->mlx_ptr, data->img1);
}

void	render_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->height = SIZE_IMG;
	data->width = SIZE_IMG;
	data->path = PATH_PLAYER;
	data->img1 = mlx_xpm_file_to_image(data->mlx_ptr, data->path,
			&data->width, &data->height);
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img1, j * SIZE_IMG, i * SIZE_IMG);
		}
	}
	mlx_destroy_image(data->mlx_ptr, data->img1);
}

void	render_exit(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->height = SIZE_IMG;
	data->width = SIZE_IMG;
	data->path_exit = PATH_EXIT;
	data->img1 = mlx_xpm_file_to_image(data->mlx_ptr, data->path_exit,
			&data->width, &data->height);
	while (data->map.map[++i])
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (data->map.map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img1, j * SIZE_IMG, i * SIZE_IMG);
		}
	}
	mlx_destroy_image(data->mlx_ptr, data->img1);
}
