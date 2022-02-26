/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:40:10 by maquentr          #+#    #+#             */
/*   Updated: 2022/02/26 18:03:01 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <errno.h>
# include <mlx.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR 1
# define UP 0
# define RIGHT 1
# define DOWN 2
# define LEFT 3
# define SIZE_IMG 36
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define PATH_PLAYER "./img/5.xpm"
# define PATH_COLLEC "./img/key.xpm"
# define PATH_EXIT "./img/e2.xpm"
# define PATH_WALL "./img/wm.xpm"
# define PATH_GROUND "./img/water.xpm"
# define PATH_MOVE_UP "./img/back.xpm"
# define PATH_MOVE_LEFT "./img/left.xpm"
# define PATH_MOVE_DOWN "./img/forward.xpm"
# define PATH_MOVE_RIGHT "./img/right.xpm"
# define NBR_IMG 9
# define COLOR 0x0000FF

typedef struct s_map
{
	char	**map;
	int		e;
	int		c;
	int		p;
	int		row;
	int		col;
	int		wallsi;
	int		wallsj;
	int		playerposi;
	int		playerposj;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_kbd
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	up;
	bool	down;
	bool	left;
	bool	right;
}	t_kbd;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img1;
	void	*img2;
	char	*path;
	char	*path1;
	char	*path2;
	char	*path_exit;
	int		height;
	int		width;
	int		nb_mouv;
	t_img	img;
	t_kbd	kbd;
	t_map	map;
}	t_data;

/* move.c */
int		render_after_minimize(t_data *data);
void	ft_endgame(t_data *data);
void	render_map(t_data *data, int direction);
void	render_background_on_player_pos(t_data *data, int i, int j);

/* checker_moves.c */
int		ft_check_if_endgame(t_data *data, int i, int j, int direction);
int		ft_check_move_possible(t_data *data, int i, int j, int direction);
int		check_collec_left(t_data *data);
int		get_player_pos(t_data *data);

/* ft_split.c */
char	**ft_split(const char *s, char c);

/* ft_strdup.c */
char	*ft_strdup(const char *s1);

/* ft_utils.c */
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	check_if_image_exists(t_data *data);

/* get_next_line.c */
char	*get_next_line(int fd);

/* handles.c */
int		handle_close_cross(t_data *data);
int		handle_keypress(int keysym, t_data *data);

/* main.c */
int		main(int ac, char **av);
void	full_check_init(int fd, char **av, t_data *data);
int		check_images(void);
int		check_rights_images(const char *path);

/* map_check.c */
int		ft_strlen(char *str);
int		check_map_extension(char *av);
int		check_map(int fd, char *av);

/* move.c */
int		render_after_minimize(t_data *data);
void	ft_endgame(t_data *data);
void	render_map(t_data *data, int direction);
void	render_background_on_player_pos(t_data *data, int i, int j);

/* parsing.c */
int		get_nb_row(int fd);
char	**fill_map(int fd, char **av);
int		parsing_map(int fd, char **av, t_data *data);
int		map_null(int fd, char **av);

/* parsing2.c */
void	free_map(char **map);
int		check_tiles(t_data *data);
void	get_char_tile(char m, t_data *data);
int		check_rect_map(t_data *data);
int		check_walls(t_data *data);

/* render.c */
void	render_ground(t_data *data);
void	render_walls(t_data *data);
void	render_collectibles(t_data *data);
void	render_player(t_data *data);
void	render_exit(t_data *data);

/* render_move.c */
void	aff_nb_mouv(t_data *data);
void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);

/* render_move2.c */
void	render_move(t_data *data, int i, int j);
void	render_move_up(t_data *data, int i, int j);
void	render_move_down(t_data *data, int i, int j);
void	render_move_left(t_data *data, int i, int j);
void	render_move_right(t_data *data, int i, int j);

/* utils_parsing.c */
char	*ft_strchr(char const *s, int c);
int		ft_size_col(const char *str);
int		ft_size_col2(char **str, int p);
int		ft_size_row(char **str);
int		ft_size_row2(char **str, int p);

/* window.c */
void	render_all(t_data *data);
void	init_window(t_data *data);
int		close_win(t_data *data);
void	set_hooks(t_data *data);

#endif
