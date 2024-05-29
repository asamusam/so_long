/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamuilk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:00:38 by asamuilk          #+#    #+#             */
/*   Updated: 2024/01/20 19:51:44 by asamuilk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keydown_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		close_window(vars);
	else if (keycode == XK_Up)
		move_player_up(vars);
	else if (keycode == XK_Down)
		move_player_down(vars);
	else if (keycode == XK_Left)
		move_player_left(vars);
	else if (keycode == XK_Right)
		move_player_right(vars);
	return (0);
}

int	closebutton_hook(t_vars *vars)
{
	close_window(vars);
	return (0);
}
