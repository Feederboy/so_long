/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:20:19 by matt              #+#    #+#             */
/*   Updated: 2022/02/26 16:58:18 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aff_nb_mouv(t_data *data)
{
	static int	count = 0;
	int			j;

	(void)data;
	j = -1;
	count++;
	ft_putstr_fd(" nb steps: ", 1);
	ft_putnbr_fd(count, 1);
	ft_putchar_fd('\n', 1);
}

void	move_up(t_data *data)
{
	get_player_pos(data);
	data->width = SIZE_IMG;
	data->height = SIZE_IMG;
	data->path = PATH_MOVE_UP;
	data->img1 = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path, &data->width, &data->height);
	check_if_image_exists(data);
	render_move(data, data->map.playerposi, data->map.playerposj);
	if (ft_check_move_possible(data, data->map.playerposi,
			data->map.playerposj, UP) == 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->img1);
		return ;
	}
	aff_nb_mouv(data);
	render_move_up(data, data->map.playerposi, data->map.playerposj);
	mlx_destroy_image(data->mlx_ptr, data->img1);
	render_map(data, UP);
}

void	move_left(t_data *data)
{
	get_player_pos(data);
	data->width = SIZE_IMG;
	data->height = SIZE_IMG;
	data->path = PATH_MOVE_LEFT;
	data->img1 = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path, &data->width, &data->height);
	check_if_image_exists(data);
	render_move(data, data->map.playerposi, data->map.playerposj);
	if (ft_check_move_possible(data, data->map.playerposi,
			data->map.playerposj, LEFT) == 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->img1);
		return ;
	}
	aff_nb_mouv(data);
	render_move_left(data, data->map.playerposi, data->map.playerposj);
	mlx_destroy_image(data->mlx_ptr, data->img1);
	render_map(data, LEFT);
}

void	move_right(t_data *data)
{
	get_player_pos(data);
	data->width = SIZE_IMG;
	data->height = SIZE_IMG;
	data->path = PATH_MOVE_RIGHT;
	data->img1 = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path, &data->width, &data->height);
	check_if_image_exists(data);
	render_move(data, data->map.playerposi, data->map.playerposj);
	if (ft_check_move_possible(data, data->map.playerposi,
			data->map.playerposj, RIGHT) == 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->img1);
		return ;
	}
	aff_nb_mouv(data);
	render_move_right(data, data->map.playerposi, data->map.playerposj);
	mlx_destroy_image(data->mlx_ptr, data->img1);
	render_map(data, RIGHT);
}

void	move_down(t_data *data)
{
	get_player_pos(data);
	data->width = SIZE_IMG;
	data->height = SIZE_IMG;
	data->path = PATH_MOVE_DOWN;
	data->img1 = mlx_xpm_file_to_image(data->mlx_ptr,
			data->path, &data->width, &data->height);
	check_if_image_exists(data);
	render_move(data, data->map.playerposi, data->map.playerposj);
	if (ft_check_move_possible(data, data->map.playerposi,
			data->map.playerposj, DOWN) == 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->img1);
		return ;
	}
	aff_nb_mouv(data);
	render_move_down(data, data->map.playerposi, data->map.playerposj);
	mlx_destroy_image(data->mlx_ptr, data->img1);
	render_map(data, DOWN);
}
