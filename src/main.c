/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/26 17:17:05 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_program(t_vars *vars)
{
	if (vars->win_ptr)
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	if (vars->img.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->img.img_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	free_map(vars->map, vars->map_height);
}

int	main(int argc, char **argv)
{
	int		**map;
	int		width;
	int		height;
	t_vars	mlx;

	if (valid_arguments(argc, argv))
	{
		map = check_and_create_map(argv[1], &width, &height);
		if (!map)
			exit (1);
		mlx.zoom = 20;
		mlx.z_scale = 1;
		mlx.offset.x = 400;
		mlx.offset.y = 250;
		mlx.win_ptr = NULL;
		start_rendering(&mlx, map, width, height);
		exit_program(&mlx);
		return (0);
	}
	return (1);
}
