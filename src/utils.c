/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <asamuilk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:38:46 by asamuilk          #+#    #+#             */
/*   Updated: 2024/01/22 13:37:09 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->m_height)
	{
		free(map[i]);
		i ++;
	}
	free(map);
}

void	error(char *error, int type)
{
	if (type == PERROR)
		perror(error);
	else
		write(STDERR_FILENO, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

void	open_window(t_vars *vars, char *name)
{
	vars->win = mlx_new_window(vars->mlx, vars->w_width, vars->w_height, name);
	if (!vars->win)
		exit(EXIT_FAILURE);
}

void	close_window(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 17)
		mlx_destroy_image(vars->mlx, vars->collect->frames[i++]);
	mlx_destroy_image(vars->mlx, vars->back->img);
	mlx_destroy_image(vars->mlx, vars->wall->img);
	mlx_destroy_image(vars->mlx, vars->finish->img);
	mlx_destroy_image(vars->mlx, vars->player->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->back);
	free(vars->wall);
	free(vars->collect);
	free(vars->finish);
	free(vars->player);
	free(vars->mlx);
	free_map(vars->map, vars);
	exit(EXIT_SUCCESS);
}
