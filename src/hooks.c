/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/26 20:28:40 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(int keycode, t_vars *param)
{
	if (keycode == 65307)
	{
		printf("ESC key pressed, closing the window...\n");
		mlx_loop_end(param->mlx_ptr);
	}
	return (0);
}

int	close_window_button(t_vars *param)
{
	printf("Close button clicked, closing the window...\n");
	mlx_loop_end(param->mlx_ptr);
	return (0);
}

void	setup_hooks(t_vars *mlx)
{
	mlx_mouse_hook(mlx->win_ptr, mouse_button_press, mlx);
}
