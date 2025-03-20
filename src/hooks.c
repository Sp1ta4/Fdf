/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:03 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/20 16:43:43 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// static void	exit_print_model(void)
// {
// 	const char	*msg1;
// 	const char	*msg2;

// 	msg1 = "Error: Insufficient arguments.\n";
// 	msg2 = "Usage: ./fdf *.fdf\n";
// 	write(2, msg1, ft_strlen(msg1));
// 	write(2, msg2, ft_strlen(msg2));
// 	exit(2);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
// {
//     int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
//     int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
//     int err = dx + dy, e2;

//     while (1)
//     {
//         my_mlx_pixel_put(data, x0, y0, color);
//         if (x0 == x1 && y0 == y1) break;
//         e2 = 2 * err;
//         if (e2 >= dy) { err += dy; x0 += sx; }
//         if (e2 <= dx) { err += dx; y0 += sy; }
//     }
// }

int close_window(int keycode, t_vars *param)
{
    if (keycode == 65307) // ESC key
    {
        printf("ESC key pressed, closing the window...\n");
        mlx_loop_end(param->mlx_ptr);  // Завершаем цикл и закрываем окно
    }
    return (0);
}

int	close_window_button(t_vars *param)
{
    printf("Close button clicked, closing the window...\n");
    mlx_loop_end(param->mlx_ptr);  // Завершаем цикл и закрываем окно
    return (0);
}

// int mouse_button_press(int button, int x, int y, __attribute__((unused)) t_vars *param)
// {
//     if (button == 1)  // Левая кнопка мыши
//         printf("Left mouse button clicked at %d, %d\n", x, y);
//     return (0);
// }

int resize_window(int width, int height, __attribute__((unused)) t_vars *param)
{
    printf("Window resized to %d x %d\n", width, height);
    return (0);
}

int window_focus_in(__attribute__((unused)) t_vars *param)
{
    printf("Window focused\n");
    return (0);
}

int window_focus_out(__attribute__((unused)) t_vars *param)
{
    printf("Window lost focus\n");
    return (0);
}

int redraw_window(__attribute__((unused)) t_vars *param)
{
    printf("Window needs to be redrawn\n");
    return (0);
}


// int main(void)
// {
//     void *mlx;
//     void *mlx_window;

//     mlx = mlx_init();
//     mlx_window = mlx_new_window(mlx, 800, 600, "All Events Example");

//     // Обработчики событий
//     mlx_key_hook(mlx_window, close_window, mlx);  // Клавиши
//     mlx_mouse_hook(mlx_window, mouse_button_press, mlx);  // Мышь
//     mlx_hook(mlx_window, 22, 1L << 0, resize_window, mlx);  // Изменение размера
//     mlx_hook(mlx_window, 9, 1L << 0, window_focus_in, mlx);  // Получение фокуса
//     mlx_hook(mlx_window, 10, 1L << 0, window_focus_out, mlx);  // Потеря фокуса
//     mlx_hook(mlx_window, 12, 1L << 0, redraw_window, mlx);  // Перерисовка

//     mlx_loop(mlx);  // Основной цикл
//     return (0);

// }

