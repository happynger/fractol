/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:03:58 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/09 14:51:48 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		hook_mouse_down(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
	{
		zoom(x, y, &mlx->viewport, 1 / ZOOMVAR);
		render(mlx);
	}
	else if (button == 5)
	{
		zoom(x, y, &mlx->viewport, ZOOMVAR);
		render(mlx);
	}
	if (y < 0)
		return (0);
	mlx->mouse.is_down |= 1 << button;
	return (0);
}

int		hook_mouse_up(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse.is_down &= ~(1 << button);
	return (0);
}

int		hook_mouse_move(int x, int y, t_mlx *mlx)
{
	double	w;
	double	h;
	
	mlx->mouse.x_last = mlx->mouse.x;
	mlx->mouse.y_last = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (!mlx->is_mouselocked)
		mlx->viewport.mouse = screen_to_const(x, y, &mlx->viewport);
	if (mlx->mouse.is_down & (1 << 1))
	{
		w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
		h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
		mlx->viewport.offx += (double)(mlx->mouse.x_last - mlx->mouse.x)
			/ WIDTH * w;
		mlx->viewport.offy += (double)(mlx->mouse.y_last - mlx->mouse.y)
			/ HEIGHT * h;
	}
	if (mlx->mouse.is_down || (mlx->fractal->mouse && !mlx->is_mouselocked))
		render(mlx);
	return (0);
}
