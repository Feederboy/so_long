/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:54:02 by matt              #+#    #+#             */
/*   Updated: 2022/02/26 00:19:22 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_image_exists(t_data *data)
{
	if (data->img1 == NULL)
	{
		free_map(data->map.map);
		data->map.map = NULL;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
		write(2, "Error: image does not exist\n", 29);
		exit(EXIT_FAILURE);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		a = n * -1;
	}
	else
		a = (unsigned int)n;
	if (a >= 10)
		ft_putnbr_fd(a / 10, fd);
	ft_putchar_fd(a % 10 + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	else
		write(fd, "null", 4);
}
