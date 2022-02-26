/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:53:03 by maquentr          #+#    #+#             */
/*   Updated: 2022/02/26 14:55:52 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_close_cross(t_data *data)
{
	close_win(data);
	return (1);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_win(data);
	if (keysym == 119 || keysym == 65362)
		move_up(data);
	else if (keysym == 97 || keysym == 65361)
		move_left(data);
	else if (keysym == 115 || keysym == 65364)
		move_down(data);
	else if (keysym == 100 || keysym == 65363)
		move_right(data);
	return (0);
}
