/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:28:43 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/09 13:00:54 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	*render_per_thread(void *m)
{
	t_threaders	*t;
	int			x;
	int			y;

	t = (t_threaders *)m;
	y = HEIGHT / THREADS * t->id;
	while (y < HEIGHT / THREADS * (t->id + 1))
	{
		x = 0;
		while (x < WIDTH)
		{
			*(t->mlx->pixels + y * HEIGHT + x) =
				t->mlx->fractal->pixel_func(x, y, &t->mlx->viewport, t->mlx);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	render(t_mlx *mlx)
{
	int			i;
	t_render	*r;

	i = 0;
	r = &mlx->renderer;
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].mlx = mlx;
		pthread_create(r->threads + i, NULL, render_per_thread, &(r->args[i]));
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(r->threads[i], NULL);
		i++;
	}

}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			image_setpix(mlx->img, x, y,
					get_color(*(mlx->pixels + y * WIDTH + x), mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
