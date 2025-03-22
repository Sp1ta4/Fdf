/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:03:10 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/22 19:17:03 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_print_model(void)
{
	char	*msg1;
	char	*msg2;

	msg1 = "Error: Insufficient arguments.\n";
	msg2 = "Usage: ./fdf *.fdf\n";
	ft_putstr_fd(msg1, 2);
	ft_putstr_fd(msg2, 2);
	exit(2);
}

void	exit_invalid_file(void)
{
	char	*msg1;

	msg1 = "Error: your file need to be *.fdf\n";
	ft_putstr_fd(msg1, 2);
	exit(2);
}

void create_window(t_vars *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr) {
		write(2, "Error: mlx_init failed\n", 23);
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(mlx->map, mlx->map_width);
		exit(1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_size.x, mlx->win_size.y, "FDF");
	if (!mlx->win_ptr) {
		write(2, "Error: mlx_new_window failed\n", 28);
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(mlx->map, mlx->map_width);
		exit(1);
	}
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_size.x, mlx->win_size.y);
	if (!mlx->img.img_ptr)
	{
		write(2, "Error: mlx_new_image failed\n", 28);
		exit(1);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
	mlx_key_hook(mlx->win_ptr, close_window, mlx); 
	mlx_hook(mlx->win_ptr, 17, 0, close_window_button, mlx);
}

void	clear_image(t_img *img, int width, int height, int color)
{
	int x, y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(img, (t_point){x, y}, color);
			x++;
		}
		y++;
	}
}