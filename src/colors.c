/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:40:15 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/09 14:28:04 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int			ft_lerpi(int f, int s, double p)
{
	if (f == s)
		return (f);
	return ((int)((double)f + (s - f) * p));
}

t_color		color_lerp(t_color c1, t_color c2, double p)
{
	t_color	c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}

t_color		linear_color(double i, int max, t_pallete *p)
{
	double	index;
	double	offset;
	int		c;

	if (p->i)
		index = fmod(i, p->i - 1) / (p->i - 1);
	else
		index = i / max;
	c = p->counter - 1;
	offset = fmod(index, 1.0f / c) * c;
	return (color_lerp((t_color)(p->color[(int)(index * c) + 1]),
		(t_color)(p->color[(int)(index * c)]),
		(int)(offset + 1) - offset));
}

t_color		smooth_color(t_pixel p, int max, t_pallete *pal)
{
	double	i;
	double	zn;
	double	nu;

	zn = log(p.c.r * p.c.r + p.c.i * p.c.i) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = p.i + 1 - nu;
	if (i < 0)
		i = 0;
	return (linear_color(i, max, pal));
}

int			get_colors(t_pixel p, t_mlx *mlx)
{
	if (p.i >= mlx->viewport.max)
		return (0x000000);
	if (mlx->is_smooth == true)
		return (smooth_color(p, mlx->viewport.max, mlx->palleter).value);
	return (linear_color((double)p.i, mlx->viewport.max, mlx->palleter).value);
}
