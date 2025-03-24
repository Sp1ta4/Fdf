/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons_panel2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:30:49 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/24 14:14:01 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_sidebar(t_vars *mlx, int width, int height)
{
	draw_rect(&(mlx->img), (t_point){2, SIDEBAR_TOP},
		(t_point){width, height}, LINE_CLR);
	create_btns(mlx);
}
