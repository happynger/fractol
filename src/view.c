/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:54:18 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/09 14:57:12 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	screen_to_view(t_view *view)
{
	double	w;
	double	h;

	w = view->xmax - view->xmin;
	h = view->ymax - view->ymin;
	if (w / h >= (float)WIDTH / HEIGHT)
	{
		view->ymin = -(w * HEIGHT / WIDTH / 2);
		view->ymax = (w * HEIGHT / WIDTH / 2);
	}
	else
	{
		view->xmin = -(h * WIDTH / HEIGHT / 2);
		view->xmax = (h * WIDTH / HEIGHT / 2);
	}
}

void		set_view(t_mlx *mlx)
{
	mlx->viewport.offx = 0;
	mlx->viewport.offy = 0;
	mlx->fractal->view_func(&mlx->viewport);
	screen_to_view(&mlx->viewport);
	mlx->viewport.max = 32;
	mlx->viewport.zoom = 1.0f;
}

t_const		screen_to_const(int x, int y, t_view *v)
{
	t_const		p;

	p.r = (((double)x / WIDTH) * (v->xmax - v->xmin)) * v->zoom
			+ v->xmin + v->offx;
	p.i = (((double)y / HEIGHT) * (v->ymax - v->ymin)) * v->zoom
			+ v->ymin + v->offy;
	return (p);
}
