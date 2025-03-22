/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/22 19:00:03 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		start_rendering(&mlx, map, width, height);
		mlx_destroy_display(mlx.mlx_ptr);
		free_map(map, height);
		return (0);
	}
	return (1);
}
