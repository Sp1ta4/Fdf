/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:03:10 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/24 12:26:35 by ggevorgi         ###   ########.fr       */
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

void	window_err(t_vars *mlx, char *err_msg)
{
	write(2, err_msg, ft_strlen(err_msg));
	mlx_destroy_display(mlx->mlx_ptr);
	free_map(mlx->map, mlx->map_width);
	exit(1);
}

void	init_img(t_vars *m)
{
	t_img	*i;

	i = &m->img;
	i->img_ptr = mlx_new_image(m->mlx_ptr, m->win_size.x, m->win_size.y);
	if (!i->img_ptr)
	{
		write(2, "Error: mlx_new_image failed\n", 28);
		exit(1);
	}
	i->addr = mlx_get_data_addr(i->img_ptr, &i->bpp, &i->l_length, &i->endian);
}

void	create_window(t_vars *mlx)
{
	void	*mlx_p;
	char	*wn;

	wn = "FDF";
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		window_err(mlx, "Error: mlx_init failed\n");
	mlx_p = mlx->mlx_ptr;
	mlx->win_ptr = mlx_new_window(mlx_p, mlx->win_size.x, mlx->win_size.y, wn);
	if (!mlx->win_ptr)
		window_err(mlx, "Error: mlx_new_window failed\n");
	init_img(mlx);
	mlx_key_hook(mlx->win_ptr, close_window, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_window_button, mlx);
}
