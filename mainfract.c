/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfract.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:33:50 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/09 13:01:56 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		hook_expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
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
	mlx_expose_hook(mlx->win, hook_expose, mlx);
}