/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:53:03 by maquentr          #+#    #+#             */
/*   Updated: 2022/02/26 18:05:21 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close_cross(t_data *data)
{
	close_win(data);
	return (1);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_win(data);
	if (keycode == KEY_W || keycode == 126)
		move_up(data);
	else if (keycode == KEY_A || keycode == 123)
		move_left(data);
	else if (keycode == KEY_S || keycode == 125)
		move_down(data);
	else if (keycode == KEY_D || keycode == 124)
		move_right(data);
	return (0);
}
