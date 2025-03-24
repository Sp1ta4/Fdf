/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:33:32 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/24 14:25:27 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	right(t_vars *vars)
{
	vars->offset.x += 10;
	if (vars->offset.x >= WINDOW_WIDTH - 50)
		vars->offset.x = WINDOW_WIDTH - 50;
}

void	zoom_out(t_vars *vars)
{
	vars->zoom -= 4;
	if (vars->zoom < 4)
		vars->zoom = 4;
	vars->z_scale = vars->zoom / 6;
	if (vars->z_scale < 1)
		vars->z_scale = 1;
	vars->needs_redraw = 1;
}

void	change_view(t_views views, t_vars *vars)
{
	vars->offset.x = 400 + SIDEBAR_WIDTH;
	vars->offset.y = 250;
	vars->default_view = views.default_v;
	vars->front_view = views.front;
	vars->side_view = views.right;
	vars->top_view = views.top;
}

void	button_action(int btn_id, t_vars *vars)
{
	if (btn_id == 0)
		change_view((t_views){1, 0, 0, 0}, vars);
	else if (btn_id == 1)
		change_view((t_views){0, 0, 0, 1}, vars);
	else if (btn_id == 2)
		change_view((t_views){0, 0, 1, 0}, vars);
	else if (btn_id == 3)
		change_view((t_views){0, 1, 0, 0}, vars);
	else if (btn_id == 4)
		zoom_in(vars);
	else if (btn_id == 5)
		zoom_out(vars);
	else if (btn_id == 6)
		left(vars);
	else if (btn_id == 7)
		right(vars);
	else if (btn_id == 8)
		down(vars);
	else if (btn_id == 9)
		up(vars);
}

int	mouse_button_press(int button, int x, int y, t_vars *vars)
{
	int	i;

	i = 0;
	(void) button;
	while (i < vars->buttons_cnt)
	{
		if (x >= vars->buttons[i].pos.x && x <= vars->buttons[i].pos.x
			+ vars->buttons[i].size.x && y >= vars->buttons[i].pos.y
			&& y <= vars->buttons[i].pos.y + vars->buttons[i].size.y)
		{
			printf("Button %d clicked: %s\n", i, vars->buttons[i].content);
			button_action(i, vars);
			vars->needs_redraw = 1;
			break ;
		}
		i++;
	}
	return (0);
}
