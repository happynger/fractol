/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:01:58 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/09 18:13:19 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_pixel		tricorn_pixelf(int x, int y, t_view *v, t_mlx *mlx)
{
	t_const		z;
	t_const		c;
	t_const		temp;
	int			i;

	(void)mlx;
	z = screen_to_const(x, y, v);
	c = screen_to_const(x, y, v);
	i = 0;
	while (z.r * z.r + z.i * z.i < (1 << 8) && i < v->max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = -2 * z.r * z.i + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return ((t_pixel){.c = z, .i = i});
}

void		tricorn_viewf(t_view *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.5f;
	v->ymax = 1.5f;
	v->offx = -0.25f;
	v->offy = -0.15f;
}
