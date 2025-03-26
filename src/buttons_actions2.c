/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons_actions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:09:29 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/26 18:42:46 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	left(t_vars *vars)
{
	vars->offset.x -= 10;
	if (vars->offset.x <= WINDOW_WIDTH / 2)
		vars->offset.x = WINDOW_WIDTH / 2;
}

void	zoom_in(t_vars *vars)
{
	if (vars->zoom < 45)
	{
		vars->zoom += 4;
		vars->z_scale += 4.0 / 3.0;
		if (vars->z_scale > 7)
			vars->z_scale = 7;
	}
	vars->needs_redraw = 1;
}

void	up(t_vars *vars)
{
	vars->offset.y -= 10;
	if (vars->offset.y <= WINDOW_HEIGHT - (WINDOW_HEIGHT - 20))
		vars->offset.y = WINDOW_HEIGHT - (WINDOW_HEIGHT - 20);
}

void	down(t_vars *vars)
{
	vars->offset.y += 10;
	if (vars->offset.y >= WINDOW_HEIGHT - 20)
		vars->offset.y = WINDOW_HEIGHT - 20;
}
