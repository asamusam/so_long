/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:31:47 by asamuilk          #+#    #+#             */
/*   Updated: 2024/01/21 21:29:52 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_background(t_vars *vars)
{
	t_object	*t;
	char		*path;

	t = malloc(sizeof(t_object));
	if (!t)
		error("malloc", PERROR);
	path = "textures/background.xpm";
	t->img = mlx_xpm_file_to_image(vars->mlx, path, &t->width, &t->height);
	if (!t->img)
		error("background mlx_file_to_image", PERROR);
	vars->back = t;
}

void	init_wall(t_vars *vars)
{
	t_object	*t;
	char		*path;

	t = malloc(sizeof(t_object));
	if (!t)
		error("malloc", PERROR);
	path = "textures/wall.xpm";
	t->img = mlx_xpm_file_to_image(vars->mlx, path, &t->width, &t->height);
	if (!t->img)
		error("wall mlx_file_to_image", PERROR);
	vars->wall = t;
}

void	init_finish(t_vars *vars)
{
	t_object	*t;
	char		*path;

	t = malloc(sizeof(t_object));
	if (!t)
		error("malloc", PERROR);
	path = "sprites/finish.xpm";
	t->img = mlx_xpm_file_to_image(vars->mlx, path, &t->width, &t->height);
	if (!t->img)
		error("finish mlx_file_to_image", PERROR);
	vars->finish = t;
}

void	init_collect(t_vars *vars)
{
	t_object	*t;
	char		*path;
	char		*str;
	char		*n_str;
	int			i;

	t = malloc(sizeof(t_object));
	if (!t)
		error("malloc", PERROR);
	i = 0;
	while (i < 17)
	{
		str = ft_itoa(i);
		n_str = ft_strjoin("sprites/Melon_", str);
		path = ft_strjoin(n_str, ".xpm");
		free(str);
		free(n_str);
		t->frames[i] = mlx_xpm_file_to_image(vars->mlx, path, \
											&t->width, &t->height);
		if (!t->frames[i++])
			error("collect mlx_file_to_image", PERROR);
		free(path);
	}
	vars->collect = t;
	vars->collect->f = 0;
}

void	init_player(t_vars *vars)
{
	t_object	*t;
	char		*path;

	t = malloc(sizeof(t_object));
	if (!t)
		error("malloc", PERROR);
	path = "sprites/player.xpm";
	t->img = mlx_xpm_file_to_image(vars->mlx, path, &t->width, &t->height);
	if (!t->img)
		error("player mlx_file_to_image", PERROR);
	vars->player = t;
}
