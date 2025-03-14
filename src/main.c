/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/14 14:04:05 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int draw(void *param)
{
    // mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    return (0);
}

int main(void)
{
    t_vars mlx;

    mlx.mlx_ptr = mlx_init();
    if (!mlx.mlx_ptr) {
        write(2, "Error: mlx_init failed\n", 23);
        return (1);
    }
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1500, 1000, "Triangle");
    if (!mlx.win_ptr) {
        write(2, "Error: mlx_new_window failed\n", 28);
        return (1);
    }
    // Устанавливаем функцию, которая будет вызываться на каждом кадре
    mlx_loop_hook(mlx.mlx_ptr, draw, &mlx);
    mlx_loop(mlx.mlx_ptr); // Входим в основной цикл
    return (0);
}