/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons_actions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:09:29 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/22 19:09:47 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void zoom_in(t_vars *vars)
{
    vars->zoom += 4;
    if (vars->zoom > 45)
        vars->zoom = 45;

    vars->z_scale = vars->zoom / 6;
    if (vars->z_scale > 7)
        vars->z_scale = 7;

    vars->needs_redraw = 1;
}

void up(t_vars *vars)
{
	if (vars->offset.y <= WINDOW_HEIGHT - (WINDOW_HEIGHT - 20))
		vars->offset.y = WINDOW_HEIGHT - (WINDOW_HEIGHT - 20);
	vars->offset.y -= 10;
}

void down(t_vars *vars)
{
	if (vars->offset.y >= WINDOW_HEIGHT - 20)
		vars->offset.y = WINDOW_HEIGHT - 20;
	vars->offset.y += 10;
}
