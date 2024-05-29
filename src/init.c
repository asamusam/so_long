/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:07 by asamuilk          #+#    #+#             */
/*   Updated: 2024/01/21 13:56:26 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		error("mlx_init", PERROR);
}

void	init(t_vars *vars)
{
	init_mlx(vars);
	init_background(vars);
	init_wall(vars);
	init_player(vars);
	init_collect(vars);
	init_finish(vars);
	vars->moves = 0;
}
