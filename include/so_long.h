/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <asamuilk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:16:00 by asamuilk          #+#    #+#             */
/*   Updated: 2024/05/29 17:28:33 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define RED 0xFF0000
# define PURPLE 0x7F00FF
# define XK_MISCELLANY
# define PERROR 0
# define WRITE 1
# define TILE_SIZE 32
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4
# define W_NAME "so_long | asamuilk | school 42"
# include <X11/keysymdef.h>
# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_object
{
	int		x;
	int		y;
	int		width;
	int		height;
	void	*img;
	void	*frames[17];
	int		f;
}	t_object;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			w_width;
	int			w_height;
	char		**map;
	int			m_width;
	int			m_height;
	int			m_collect;
	int			collected;
	int			exit;
	int			moves;
	t_object	*player;
	t_object	*back;
	t_object	*wall;
	t_object	*finish;
	t_object	*collect;
}	t_vars;

void	error(char *error, int type);
void	open_window(t_vars *vars, char *name);
void	close_window(t_vars *vars);
void	free_map(char **map, t_vars *vars);

int		keydown_hook(int keycode, t_vars *vars);
int		closebutton_hook(t_vars *vars);

void	init(t_vars *vars);
void	init_background(t_vars *vars);
void	init_wall(t_vars *vars);
void	init_finish(t_vars *vars);
void	init_collect(t_vars *vars);
void	init_player(t_vars *vars);

void	parse_map(t_vars *vars, char *file);

void	draw(t_vars *vars);

void	move_player_up(t_vars *vars);
void	move_player_down(t_vars *vars);
void	move_player_left(t_vars *vars);
void	move_player_right(t_vars *vars);

void	check_map_size(t_vars *vars);
void	check_map_content(t_vars *vars);
void	check_character(t_vars *vars, int i, int j);
int		count_exit(char c);
int		count_start(char c);
int		count_collect(char c);
void	check_path(t_vars *vars);

#endif