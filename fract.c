/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:21:45 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/08 19:51:12 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_mlx	*destroy_mlx(t_mlx *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->img != NULL)
		destroy_image(mlx->mlx, mlx->img);
}

t_mlx	*init(t_fractal *f)
{
	t_mlx	*mlx;
	char	*tmp;

	CHECK_NULL((mlx = ft_memalloc(sizeof(t_mlx))));
	tmp = ft_strjoin("Fractol -> ", f->name);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, tmp)) == NULL ||
		(mlx->img = new_image(mlx)) == NULL ||
		(mlx->pixels = ft_memalloc(sizeof(t_pixel) * WIDTH * HEIGHT)) == NULL)
		return (destroy_mlx(mlx));
	mlx->mouse.is_down = false;
	mlx->fractal = f;
	mlx->is_mouselocked = (f->mouse == 0) ? true : false;
	mlx->palleter = get_palletes();
	mlx->is_smooth = true;
	return (mlx);
}
