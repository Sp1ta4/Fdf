/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:33:32 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/21 16:14:04 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void zoom_in(t_vars *vars)
{
	vars->zoom += 4;
	if (vars->zoom > 45)
		vars->zoom = 45;
}
void zoom_out(t_vars *vars)
{
	vars->zoom -= 4;
	if (vars->zoom < 10)
		vars->zoom = 10;
}


void	button_action(int btn_id, t_vars *vars)
{
	if (btn_id == 0) //Default
	{
		vars->default_view = 1;
		vars->front_view = 0;
		vars->side_view = 0;
		vars->top_view = 0;
	}
	else if (btn_id == 1) //Front
	{
		vars->front_view = 1;
		vars->side_view = 0;
		vars->top_view = 0;
		vars->default_view = 0;
	}
	else if (btn_id == 2) //Right
	{
		vars->side_view = 1;
		vars->front_view = 0;
		vars->default_view = 0;
		vars->top_view = 0;
	}
	else if (btn_id == 3) //Top
	{
		vars->top_view = 1;
		vars->front_view = 0;
		vars->side_view = 0;
		vars->default_view = 0;
	}
	else if (btn_id == 4) //Zoom in +
		zoom_in(vars);	
	else if (btn_id == 5) //Zoom out -
		zoom_out(vars);
}

int	mouse_button_press(__attribute__((unused)) int button, int x, int y, t_vars *vars)
{
	int i;

	i = 0;
	while (i < vars->buttons_cnt)
	{
		if (x >= vars->buttons[i].pos.x && x <= vars->buttons[i].pos.x + vars->buttons[i].size.x &&
			y >= vars->buttons[i].pos.y && y <= vars->buttons[i].pos.y + vars->buttons[i].size.y)
		{
			printf("Button %d clicked: %s\n", i, vars->buttons[i].content);
			button_action(i, vars);
			vars->needs_redraw = 1;
			break;
		}
		i++;
	}
	return (0);
}