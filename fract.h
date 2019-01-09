/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:26:29 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/09 13:01:48 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <math.h>
# include <stdint.h>
# include "./minilibx_macos/mlx.h"
# include <stdbool.h>
# include <pthread.h>
# include "./libft/includes/libft.h"

# define HEIGHT 720
# define WIDTH 1080
# define ZOOMVAR 1.0f
# define THREADS 8

typedef struct			s_rgba
{
	uint8_t				r;
	uint8_t				g;
	uint8_t				b;
	uint8_t				a;
}						t_rgba;

typedef struct			s_image
{
	void				*img;
	char				*ptr;
	int					bpp;
	int					stride;
	int					endian;
}						t_image;

typedef struct			s_const
{
	long				r;
	long				i;
}						t_const;

typedef struct			s_view
{
	double				xmin;
	double				xmax;
	double				ymin;
	double				ymax;
	double				zoom;
	double				offx;
	double				offy;
	long				max;
	t_const				mouse;
}						t_view;

typedef struct			s_pixel
{
	t_const				c;
	long				i;
}						t_pixel;

typedef union			u_color
{
	int					value;
	t_rgba				rgba;
}						t_color;

typedef struct			s_pallete
{
	uint8_t				counter;
	int					i;
	int					color[16];
}						t_pallete;

typedef struct s_mlx	t_mlx;

typedef void			(*t_func_v)(t_view *v);
typedef t_pixel			(*t_func_p)(int x, int y, t_view *v, t_mlx *mlx);

typedef struct			s_fractal
{
	char				*name;
	t_func_v			view_func;
	t_func_p			pixel_func;
	int					mouse;
}						t_fractal;

typedef struct			s_threaders
{
	int					id;
	t_mlx				*mlx;
}						t_threaders;

typedef struct			s_render
{
	pthread_t			threads[THREADS];
	t_threaders			args[THREADS];
}						t_render;

typedef struct			s_mouse
{
	bool				is_down;
	int					x;
	int					y;
	int					x_last;
	int					y_last;
}						t_mouse;

struct					s_mlx
{
	void				*mlx;
	void				*win;
	bool				is_smooth;
	bool				is_mouselocked;
	t_image				*img;
	t_fractal			*fractal;
	t_render			renderer;
	t_pixel				*pixels;
	t_view				viewport;
	t_pallete			*palleter;
	t_mouse				mouse;
};

t_fractal				*fractal_matcher(char *str);
t_image					*destroy_image(t_mlx *mlx, t_image *image);
t_image					*new_image(t_mlx *mlx);
t_pallete				*get_palletes(void);
t_mlx					*init(t_fractal *f);
void					set_view(t_mlx *mlx);
t_const					screen_to_const(int x, int y, t_view *v);
void					image_setpix(t_image *image, int x, int y, int color);
int						get_color(t_pixel p, t_mlx *mlx);
void					render(t_mlx *mlx);
void					draw(t_mlx *mlx);

t_pixel					julia_pixel(int x, int y, t_view *v, t_mlx *mlx);
void					julia_view(t_view *v);

#endif
