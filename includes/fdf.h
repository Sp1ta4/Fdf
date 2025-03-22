/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:27 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/22 19:18:18 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <math.h>

# define M_PI 3.14159265358979323846
# define FRAME_TIME 10000

# define ESC_KEYCODE 53
# define LEFT_ARROW_KEYCODE 123
# define RIGHT_ARROW_KEYCODE 124
# define BOTTOM_ARROW_KEYCODE 125
# define TOP_ARROW_KEYCODE 126
# define NUMPAD_PLUS_KEYCODE 69
# define NUMPAD_MINUS_KEYCODE 78
# define PLUS_KEYCODE 24
# define MINUS_KEYCODE 27
# define A_KEYCODE 0
# define S_KEYCODE 1
# define D_KEYCODE 2
# define W_KEYCODE 13

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	ORANGE = 0xFF4500,
	FIREBRICK = 0xB22222,
	WHITE = 0xFCFCFC,
	SILVER = 0xC0C0C0,
	BACKGROUND_COLOR = 0x000000,
	LINE_CLR = 0x8B008B
};

# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 900
# define SIDEBAR_WIDTH 280
# define SIDEBAR_HEIGHT 310
# define SIDEBAR_TOP 290

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_line
{
	t_point	delta;
	t_point	steps;
	int		err;
}	t_line;

typedef struct s_btn
{
	t_point	pos;
	t_point	size;
	void	(*action)(void *);
	char	*content;
}	t_btn;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_gradient
{
	int	color1;
	int	color2;
}	t_gradient;

typedef struct s_views
{
	int	default_v;
	int	top;
	int	right;
	int	front;
}	t_views;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_vars
{
	int		**map;
	int		map_width;
	int		map_height;
	int		buttons_cnt;
	int		default_view;
	int		top_view;
	int		side_view;
	int		front_view;
	int		zoom;
	int		angle;
	int		needs_redraw;
	int		z_scale;
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	win_size;
	t_point	sidebar_size;
	t_point	start;
	t_point	offset;
	t_img	img;
	t_btn	buttons[16];
}	t_vars;

int				create_trgb(int t, int r, int g, int b);
int				close_window(int keycode, t_vars *param);
int				valid_arguments(int argc, char **argv);
int				ft_isspace(char c);
int				**check_and_create_map(char *map_file, int *width, int *height);
int				close_window_button(t_vars *param);
int				mouse_button_press(int button, int x, int y, t_vars *vars);
int				get_color(int z);
void			show_buttons_text(t_vars *vars);
void			start_rendering(t_vars *mlx, int **map, int width, int height);
void			init_map_mlx(t_vars *mlx, int **map, int width, int height);
void			my_mlx_pixel_put(t_img *data, t_point p, int color);
void			err_invalid_map(int code);
void			free_split(char **split);
void			free_map(int **map, int rows);
void			err_exit(char *err_msg, int exit_status);
void			free_int_arr(int **arr);
void			free_ptr(void **p);
void			exit_print_model(void);
void			exit_invalid_file(void);
void			draw_line(t_img *data, t_point p0, t_point p1, t_gradient grad);
void			zoom_in(t_vars *vars);
void			up(t_vars *vars);
void			down(t_vars *vars);
void			create_window(t_vars *mlx);
void			clear_image(t_img *img, int width, int height, int color);
void			free_split(char **arr);
void			draw_rect(t_img *data, t_point pos, t_point size, int color);
void			create_btns(t_vars *mlx);
void			draw_text(t_vars *mlx, char *text);
void			create_sidebar(t_vars *mlx, int width, int height);
char			**get_splitted_line(int fd);
unsigned int	random_color(void);

#endif