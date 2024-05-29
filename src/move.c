/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:51:30 by asamuilk          #+#    #+#             */
/*   Updated: 2024/01/21 20:35:37 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_vars *vars)
{
	int		x;
	int		y;
	char	c;

	x = vars->player->x;
	y = vars->player->y;
	c = vars->map[y - 1][x];
	if (c == '1')
		return ;
	else if (c == 'C')
		vars->collected += 1;
	else if (c == 'E' && vars->collected == vars->m_collect)
		vars->exit = 1;
	else if (c == 'E' && vars->collected != vars->m_collect)
		ft_printf("%d collectibles left!\n", vars->m_collect - vars->collected);
	if (c != 'E' || vars->exit)
	{
		vars->map[y - 1][x] = 'P';
		vars->map[y][x] = '0';
		vars->player->y -= 1;
		vars->moves ++;
		ft_printf("%d\n", vars->moves);
	}
}

void	move_player_down(t_vars *vars)
{
	int		x;
	int		y;
	char	c;

	x = vars->player->x;
	y = vars->player->y;
	c = vars->map[y + 1][x];
	if (c == '1')
		return ;
	else if (c == 'C')
		vars->collected += 1;
	else if (c == 'E' && vars->collected == vars->m_collect)
		vars->exit = 1;
	else if (c == 'E' && vars->collected != vars->m_collect)
		ft_printf("%d collectibles left!\n", vars->m_collect - vars->collected);
	if (c != 'E' || vars->exit)
	{
		vars->map[y + 1][x] = 'P';
		vars->map[y][x] = '0';
		vars->player->y += 1;
		vars->moves ++;
		ft_printf("%d\n", vars->moves);
	}
}

void	move_player_left(t_vars *vars)
{
	int		x;
	int		y;
	char	c;

	x = vars->player->x;
	y = vars->player->y;
	c = vars->map[y][x - 1];
	if (c == '1')
		return ;
	else if (c == 'C')
		vars->collected += 1;
	else if (c == 'E' && vars->collected == vars->m_collect)
		vars->exit = 1;
	else if (c == 'E' && vars->collected != vars->m_collect)
		ft_printf("%d collectibles left!\n", vars->m_collect - vars->collected);
	if (c != 'E' || vars->exit)
	{
		vars->map[y][x - 1] = 'P';
		vars->map[y][x] = '0';
		vars->player->x -= 1;
		vars->moves ++;
		ft_printf("%d\n", vars->moves);
	}
}

void	move_player_right(t_vars *vars)
{
	int		x;
	int		y;
	char	c;

	x = vars->player->x;
	y = vars->player->y;
	c = vars->map[y][x + 1];
	if (c == '1')
		return ;
	else if (c == 'C')
		vars->collected += 1;
	else if (c == 'E' && vars->collected == vars->m_collect)
		vars->exit = 1;
	else if (c == 'E' && vars->collected != vars->m_collect)
		ft_printf("%d collectibles left!\n", vars->m_collect - vars->collected);
	if (c != 'E' || vars->exit)
	{
		vars->map[y][x + 1] = 'P';
		vars->map[y][x] = '0';
		vars->player->x += 1;
		vars->moves ++;
		ft_printf("%d\n", vars->moves);
	}
}
