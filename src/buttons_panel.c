/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons_panel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:39:08 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/21 15:48:53 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_buttons_text(t_vars *vars)
{
	int	i;
	int	pos_x;
	int	pos_y;

	i = 0;
	while (i < vars->buttons_cnt)
	{
		pos_x = vars->buttons[i].pos.x + 40;
		pos_y = vars->buttons[i].pos.y + 27;
		mlx_string_put(vars->mlx_ptr, vars->win_ptr, pos_x + 1, pos_y,
			WHITE, vars->buttons[i].content);
		i++;
	}
}

static void	init_btns_helpers(t_vars *mlx)
{
	mlx->buttons[0].content = "Default";
	// mlx->buttons[0].action = default_action;
	mlx->buttons[1].content = "Front";
	// mlx->buttons[1].action = front_action;
	mlx->buttons[2].content = "Right";
	// mlx->buttons[2].action = right_action;
	mlx->buttons[3].content = "Top";
	// mlx->buttons[3].action = top_action;
	mlx->buttons[4].content = "Zoom in +";
	// mlx->buttons[4].action = zoom_in_action;
	mlx->buttons[5].content = "Zoom out -";
	// mlx->buttons[5].action = zoom_out_action;
}

void create_btns(t_vars *mlx)
{
    int i;
    int gap;

    mlx->buttons_cnt = 6;
    gap = 10;
    i = 0;
    while (i < mlx->buttons_cnt)
    {
        mlx->buttons[i].size.x = 125;
        mlx->buttons[i].size.y = 50;
        if (i % 2 == 0)
            mlx->buttons[i].pos.x = 1 + gap;
        else
            mlx->buttons[i].pos.x = 127 + 2 * gap;
        mlx->buttons[i].pos.y = 300 + (i / 2) * (50 + gap);
        draw_rect(&(mlx->img), mlx->buttons[i].pos, 
                  (t_point){mlx->buttons[i].pos.x + mlx->buttons[i].size.x, 
                            mlx->buttons[i].pos.y + mlx->buttons[i].size.y}, 
                  ORANGE);

        i++;
    }
    init_btns_helpers(mlx);
	show_buttons_text(mlx);
}
