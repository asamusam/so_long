/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:37:20 by asamuilk          #+#    #+#             */
/*   Updated: 2024/01/21 13:56:03 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_wall(t_vars *vars, int i, int j)
{
	char	c;

	c = vars->map[i][j];
	if (i == 0 && c != '1')
		error("The map is not enclosed with walls.\n", WRITE);
	else if (j == 0 && c != '1')
		error("The map is not enclosed with walls.\n", WRITE);
	else if (i == vars->m_height - 1 && c != '1')
		error("The map is not enclosed with walls.\n", WRITE);
	else if (j == vars->m_width - 1 && c != '1')
		error("The map is not enclosed with walls.\n", WRITE);
}

int	count_exit(char c)
{
	static int	exit;

	if (c == 'E')
		exit ++;
	if (exit > 1)
		error("Error! The map contains more than one exit.\n", WRITE);
	return (exit);
}

int	count_start(char c)
{
	static int	start;

	if (c == 'P')
		start ++;
	if (start > 1)
		error("Error! The map contains more than one start.\n", WRITE);
	return (start);
}

int	count_collect(char c)
{
	static int	collect;

	if (c == 'C')
		collect ++;
	return (collect);
}

void	check_character(t_vars *vars, int i, int j)
{
	char	c;

	c = vars->map[i][j];
	if (c == '1')
		return ;
	else if (c == '0')
		return ;
	else if (c == 'E')
		count_exit(c);
	else if (c == 'C')
		count_collect(c);
	else if (c == 'P')
	{
		count_start(c);
		vars->player->x = j;
		vars->player->y = i;
	}
	else
		error("Error! The map contains invalid characters.\n", WRITE);
	check_wall(vars, i, j);
}
