/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:26:29 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/10 11:47:08 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <math.h>
# include <stdint.h>
# include "mlx.h"
# include <stdbool.h>
# include <pthread.h>
# include <complex.h>
# include "libft.h"
# include "structs.h"

/*
**	HEIGHT/WIDTH ->	Screen Dimentions
**	ZOOMVAR ->		The Change of zoom per key press
*/

# define HEIGHT 720
# define WIDTH 1280
# define ZOOMVAR 1.1f

/*
**	SKELETON_FUNCTIONS
*/
t_fractal				*fractal_matcher(char *str);
t_image					*destroy_image(t_mlx *mlx, t_image *image);
t_image					*new_image(t_mlx *mlx);
t_pallete				*get_palletes(void);
t_mlx					*init(t_fractal *f);
void					set_view(t_mlx *mlx);
t_const					screen_to_const(int x, int y, t_view *v);
void					image_setpix(t_image *image, int x, int y, int color);
int						get_colors(t_pixel p, t_mlx *mlx);
void					render(t_mlx *mlx);
void					draw(t_mlx *mlx);
void					zoom(int x, int y, t_view *v, double z);
int						hook_press(int key, t_mlx *mlx);
int						hook_mouse_move(int x, int y, t_mlx *mlx);
int						hook_mouse_up(int button, int x, int y, t_mlx *mlx);
int						hook_mouse_down(int button, int x, int y, t_mlx *mlx);
/*
**	FRACTAL_FUNCTIONS
*/
t_pixel					julia_pixel(int x, int y, t_view *v, t_mlx *mlx);
void					julia_view(t_view *v);
t_pixel					mandelbrot_pixelf(int x, int y, t_view *v, t_mlx *mlx);
void					mandelbrot_viewf(t_view *v);
t_pixel					multijulia_pixel(int x, int y, t_view *v, t_mlx *mlx);
void					multijulia_view(t_view *v);
t_pixel					tricorn_pixelf(int x, int y, t_view *v, t_mlx *mlx);
void					tricorn_viewf(t_view *v);

#endif
