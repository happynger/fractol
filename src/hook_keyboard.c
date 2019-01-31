/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:06:57 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/31 15:06:58 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include "keyvalues.h"

#define STEP 0.05f

int		draw_hook(int key, t_mlx *mlx)
{
	int			d;
	static int	cycle;

	d = 0;
	if (get_palletes()[cycle].counter == 0)
		cycle = 0;
	if (key == DIGIT_1)
		mlx->palleter = &get_palletes()[cycle++];
	else if (key == NUM_ENTER)
		mlx->is_smooth = (mlx->is_smooth == false) ? true : false;
	else
		d = 1;
	if (!d)
		draw(mlx);
	return (d);
}

void	move_hook(int key, t_mlx *mlx)
{
	double	ws;
	double	hs;

	ws = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
	hs = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
	if (key == UP)
		mlx->viewport.offy -= hs * STEP;
	else if (key == DOWN)
		mlx->viewport.offy += hs * STEP;
	else if (key == LEFT)
		mlx->viewport.offx -= ws * STEP;
	else if (key == RIGHT)
		mlx->viewport.offx += ws * STEP;
	else if (key == L)
		mlx->is_mouselocked = (mlx->is_mouselocked == false) ? true : false;
}

int		hook_press(int key, t_mlx *mlx)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	else if (key == RESET)
		set_view(mlx);
	else if (key == NUM_MULT)
		mlx->viewport.max *= 2;
	else if (key == NUM_DIV)
	{
		if (mlx->viewport.max / 2 >= 2)
			mlx->viewport.max /= 2;
	}
	else if (key == NUM_PLUS)
		zoom(WIDTH / 2, HEIGHT / 2, &mlx->viewport, 1 / ZOOMVAR);
	else if (key == NUM_MINUS)
		zoom(WIDTH / 2, HEIGHT / 2, &mlx->viewport, ZOOMVAR);
	else if (key == NUM_1 && mlx->n > 2)
		mlx->n--;
	else if (key == NUM_3)
		mlx->n++;
	move_hook(key, mlx);
	if (draw_hook(key, mlx))
		render(mlx);
	return (0);
}
