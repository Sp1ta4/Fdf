/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/18 18:42:58 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int draw(void *param)
{
	(void) param;
	// mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}

void	start_rendering(t_vars *mlx)
{
// 	int	xpx;
// 	int ypx;

// 	xpx = mlx->width * 50;
// 	ypx = mlx->height * 50;

	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr) {
		write(2, "Error: mlx_init failed\n", 23);
		// return (1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1500, 1000, "FDF");
	if (!mlx->win_ptr) {
		write(2, "Error: mlx_new_window failed\n", 28);
		// return (1);
	}
	// Устанавливаем функцию, которая будет вызываться на каждом кадре
	// mlx_loop_hook(mlx->mlx_ptr, draw, &mlx);
	mlx_loop(mlx->mlx_ptr);
}

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
		mlx.height = height;
		mlx.width = width;
		mlx.map = map;
		start_rendering(&mlx);
		// print_map(map, width, height);	
		free_map(map, height);
		return (0);
	}
	return (1);
}