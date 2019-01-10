/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multijulia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:45:07 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/09 17:52:16 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_pixel		multijulia_pixel(int x, int y, t_view *v, t_mlx *mlx)
{
	t_const		z;
	t_const		c;
	t_const		tmp;
	int			i;

	i = 0;
	z = screen_to_const(x, y, v);
	c = v->mouse;
	while (z.r * z.r + z.i * z.i < (1 << 8) && i < v->max)
	{
		tmp.r = pow(z.r * z.r + z.i * z.i, mlx->n / 2)
			* cos(mlx->n * atan2(z.i, z.r)) + c.r;
		tmp.i = pow(z.r * z.r + z.i * z.i, mlx->n / 2)
			* sin(mlx->n * atan2(z.i, z.r)) + c.i;
		if (z.r == tmp.r && z.i == tmp.i)
		{
			i = v->max;
			break ;
		}
		z.r = tmp.r;
		z.i = tmp.i;
		i++;
	}
	return ((t_pixel){.c = z, .i = i});
}

void		multijulia_view(t_view *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
}
