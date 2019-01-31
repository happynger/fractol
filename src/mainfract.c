/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfract.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:33:50 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/31 15:05:41 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		hook_expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
}

void	zoom(int x, int y, t_view *v, double z)
{
	double	w;
	double	h;
	double	new_w;
	double	new_h;

	w = (v->xmax - v->xmin) * v->zoom;
	h = (v->ymax - v->ymin) * v->zoom;
	new_w = (v->xmax - v->xmin) * (v->zoom * z);
	new_h = (v->ymax - v->ymin) * (v->zoom * z);
	v->zoom *= z;
	v->offx -= ((double)x / WIDTH) * (new_w - w);
	v->offy -= ((double)y / HEIGHT) * (new_h - h);
}

int		main(int ac, char **av)
{
	t_mlx		*mlx;
	t_fractal	*fractal;

	if (ac < 2)
		ft_error("Usage ->> ./fractol [Name of fractal]");
	fractal = fractal_matcher(av[1]);
	if (fractal->name == NULL)
		ft_error("Error ->> Invalid name input");
	if ((mlx = init(fractal)) == NULL)
		ft_error("Error ->> MLX failed successfully");
	set_view(mlx);
	render(mlx);
	mlx_key_hook(mlx->win, hook_press, mlx);
	mlx_expose_hook(mlx->win, hook_expose, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, hook_mouse_down, mlx);
	mlx_hook(mlx->win, 5, 1L << 3, hook_mouse_up, mlx);
	mlx_hook(mlx->win, 6, 1L << 6, hook_mouse_move, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
