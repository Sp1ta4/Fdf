/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/21 13:45:56 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int draw(void *param)
// {
// 	(void) param;
// 	// mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
// 	return (0);
// }

// void initial_line(t_point *start, t_point *end, )
// {}




int main(int argc, char **argv)
{
	int	**map;
	int	width;
	int	height;
	t_vars mlx;

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
		// print_map(map, width, height);	
		free_map(map, height);
		return (0);
	}
	return (1);
}