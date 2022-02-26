/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:53:42 by maquentr          #+#    #+#             */
/*   Updated: 2022/02/26 16:54:21 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_all(t_data *data)
{
	render_ground(data);
	render_walls(data);
	render_collectibles(data);
	render_player(data);
	render_exit(data);
	set_hooks(data);
	mlx_loop(data->mlx_ptr);
}

void	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free(data->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.row * SIZE_IMG,
			(data->map.col + 1) * SIZE_IMG, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		exit(EXIT_FAILURE);
	}
	render_all(data);
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	free(data->win_ptr);
	free_map(data->map.map);
	exit(EXIT_SUCCESS);
}

void	set_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 17, 0, handle_close_cross, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, 12, 1L << 15, render_after_minimize, data);
}
