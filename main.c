/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:40:10 by maquentr          #+#    #+#             */
/*   Updated: 2022/02/26 16:40:14 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rights_images(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(STDERR_FILENO, "Error: no permission for image\n", 32);
		exit (EXIT_FAILURE);
	}
	close(fd);
	return (1);
}

int	check_images(void)
{
	size_t		i;
	const char	*image_path[] = {PATH_PLAYER, PATH_COLLEC, PATH_EXIT, PATH_WALL,
		PATH_GROUND, PATH_MOVE_UP, PATH_MOVE_LEFT,
		PATH_MOVE_DOWN, PATH_MOVE_RIGHT};

	i = 0;
	while (i < NBR_IMG)
	{
		check_rights_images(image_path[i]);
		++i;
	}
	return (1);
}

void	full_check_init(int fd, char **av, t_data *data)
{
	check_images();
	if (check_map(fd, av[1]) == 1)
		exit (EXIT_FAILURE);
	parsing_map(fd, av, data);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac != 2)
	{
		write(2, "ERROR: check arguments\nusage: ./solong <infile.ber>\n", 52);
		return (0);
	}
	else
	{
		if (av[1] == NULL)
		{
			write(2, "ERROR: wrong infile\n", 20);
			return (0);
		}
		fd = open(av[1], O_RDONLY);
		full_check_init(fd, av, &data);
		init_window(&data);
	}
	close_win(&data);
	free(data.mlx_ptr);
	free(data.win_ptr);
	return (0);
}
