/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:08:32 by asamuilk          #+#    #+#             */
/*   Updated: 2024/01/21 13:56:12 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_vars *vars)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * vars->m_height);
	if (!copy)
		error("copy map malloc", PERROR);
	i = 0;
	while (i < vars->m_height)
	{
		copy[i] = ft_strdup(vars->map[i]);
		i ++;
	}
	return (copy);
}

static void	check_tile(t_vars *vars, char **map, int i, int j)
{
	if (map[i][j] == '1')
		return ;
	else if (map[i][j] == 'E')
	{
		vars->exit = 1;
		return ;
	}
	else if (map[i][j] == 'C')
		vars->collected += 1;
	map[i][j] = '1';
	if (i > 0)
		check_tile(vars, map, i - 1, j);
	check_tile(vars, map, i + 1, j);
	check_tile(vars, map, i, j - 1);
	check_tile(vars, map, i, j + 1);
}

void	check_path(t_vars *vars)
{
	char	**map_copy;

	map_copy = copy_map(vars);
	vars->collected = 0;
	vars->exit = 0;
	vars->m_collect = count_collect('0');
	check_tile(vars, map_copy, vars->player->y, vars->player->x);
	free_map(map_copy, vars);
	if (vars->collected < vars->m_collect)
		error("Error\nNot all collectibles are accessible.\n", WRITE);
	else if (!vars->exit)
		error("Error\nExit is inaccessible.\n", WRITE);
	vars->collected = 0;
	vars->exit = 0;
}

void	check_map_content(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->m_height)
	{
		j = 0;
		while (vars->map[i][j] != '\n')
			check_character(vars, i, j++);
		i ++;
	}
	if (!count_collect('0'))
		error("Error\nThe map does not contain any collectibles.\n", WRITE);
	if (!count_exit('0'))
		error("Error\nThe map does not have an exit.\n", WRITE);
	if (!count_start('0'))
		error("Error\nThe map does not have a start.\n", WRITE);
}

void	check_map_size(t_vars *vars)
{
	int	sizex;
	int	sizey;

	mlx_get_screen_size(vars->mlx, &sizex, &sizey);
	if (vars->m_width * TILE_SIZE > sizex || vars->m_height * TILE_SIZE > sizey)
		error("Sorry, the map is too big!\n", WRITE);
	else
	{
		vars->w_width = vars->m_width * TILE_SIZE;
		vars->w_height = vars->m_height * TILE_SIZE;
	}
}
