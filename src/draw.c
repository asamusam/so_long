/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:13:42 by asamuilk          #+#    #+#             */
/*   Updated: 2024/01/21 21:31:30 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_object(t_vars *vars, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->back->img, x, y);
	else if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall->img, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player->img, x, y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
								vars->collect->frames[vars->collect->f], x, y);
		vars->collect->f ++;
		if (vars->collect->f == 17)
			vars->collect->f = 0;
	}
	else if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->finish->img, x, y);
	else
		error("Error\nThe map contains invalid symbols.\n", WRITE);
}

void	draw(t_vars *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < vars->m_height)
	{
		x = 0;
		j = 0;
		while (vars->map[i][j] != '\n')
		{
			draw_object(vars, vars->map[i][j], x, y);
			x += TILE_SIZE;
			j ++;
		}
		y += TILE_SIZE;
		i ++;
	}
}
