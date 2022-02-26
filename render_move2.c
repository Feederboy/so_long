/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:22:07 by matt              #+#    #+#             */
/*   Updated: 2022/02/26 15:30:39 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_move(t_data *data, int i, int j)
{
	render_background_on_player_pos(data, i, j);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img1, j * SIZE_IMG, i * SIZE_IMG);
}

void	render_move_up(t_data *data, int i, int j)
{
	int	tmp;

	tmp = -1;
	while (++tmp < SIZE_IMG)
	{
		render_background_on_player_pos(data, i, j);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img1, j * SIZE_IMG, i * SIZE_IMG - tmp);
		mlx_do_sync(data->mlx_ptr);
	}
}

void	render_move_down(t_data *data, int i, int j)
{
	int	tmp;

	tmp = -1;
	while (++tmp < SIZE_IMG)
	{
		render_background_on_player_pos(data, i, j);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img1, j * SIZE_IMG, i * SIZE_IMG + tmp);
		mlx_do_sync(data->mlx_ptr);
	}
}

void	render_move_left(t_data *data, int i, int j)
{
	int	tmp;

	tmp = -1;
	while (++tmp < SIZE_IMG)
	{
		render_background_on_player_pos(data, i, j);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img1, j * SIZE_IMG - tmp, i * SIZE_IMG);
		mlx_do_sync(data->mlx_ptr);
	}
}

void	render_move_right(t_data *data, int i, int j)
{
	int	tmp;

	tmp = -1;
	while (++tmp < SIZE_IMG)
	{
		render_background_on_player_pos(data, i, j);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img1, j * SIZE_IMG + tmp, i * SIZE_IMG);
		mlx_do_sync(data->mlx_ptr);
	}
}
