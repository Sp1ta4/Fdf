/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:28:27 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/18 18:38:31 by ggevorgi         ###   ########.fr       */
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
	ORANGE = 0xFFA500,
	WHITE = 0xFCFCFC,
	GREY = 0x525252
};

# define SIDEBAR_WIDTH 200
# define LINE_COLOR 0xffb800

typedef struct s_ij
{
	int	i;
	int	j;
}	t_ij;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_line
{
	t_point	p1;
	t_point	p2;
}	t_line_cords;

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

typedef struct s_img
{
	void	*img;
	int		addr;
	int		bpp;
	int		line_length;
	int		endian;
	char	*addr_end;
}	t_img;

typedef struct s_vars
{
	int		**map;
	int		**temp_map;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	win_size;
	int		sidebar_width;
	int		x;
	int		y;
	char	*row;
	char	**row_splited;
	t_img	img;
	t_color	start_color;
	t_color	end_color;
	t_btn	buttons[16];
	int		buttons_cnt;
	int		max_z;
	double	angle;
	double	z_rotate;
	double	x_rotate;
	double	y_rotate;
	int		motion_effect;
	int		z_zoom;
	float	total_steps;
	int	top_view;
	int	right_click;
	t_point	start;
	int		field_size;
	int		progress_engine;
}	t_vars;

int				valid_arguments(int argc, char **argv);
int				ft_isspace(char c);
int				**check_and_create_map(char *map_file, int *width, int *height);
void			err_invalid_map(int code);
void			free_split(char **split);
char			**get_splitted_line(int fd);
void			free_map(int **map, int rows);
void			err_exit(char *err_msg, int exit_status);
void			free_int_arr(int **arr);
void			free_ptr(void **p);
void			exit_print_model(void);
void			exit_invalid_file(void);
// void			draw_line(t_img *data, t_point p0, t_point p1, int color);
void			free_split(char **arr);
unsigned int	random_color(void);

#endif