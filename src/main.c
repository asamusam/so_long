/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:14:02 by asamuilk          #+#    #+#             */
/*   Updated: 2024/01/21 20:38:12 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_vars *vars)
{
	if (vars->exit)
	{
		ft_printf("%s\n", "YOU WIN!");
		close_window(vars);
	}
	draw(vars);
	usleep(150000);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars		vars;

	if (ac != 2)
		error("Please, provide a map\n", WRITE);
	else
	{
		vars.mlx = mlx_init();
		if (!vars.mlx)
			error("mlx", PERROR);
		init_background(&vars);
		init_wall(&vars);
		init_player(&vars);
		init_collect(&vars);
		init_finish(&vars);
		vars.moves = 0;
		parse_map(&vars, av[1]);
		open_window(&vars, W_NAME);
		mlx_key_hook(vars.win, keydown_hook, &vars);
		mlx_hook(vars.win, 17, 0, closebutton_hook, &vars);
		mlx_loop_hook(vars.mlx, render_next_frame, &vars);
		mlx_loop(vars.mlx);
	}
}
