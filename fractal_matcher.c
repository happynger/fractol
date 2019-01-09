/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_matcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:12:32 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/08 19:48:44 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static t_fractal	*get_fractal_const(void)
{
	static t_fractal	array[5] = {
		{"mandelbrot", NULL, NULL, 0},
		{"julia", NULL, NULL, 1},
		{NULL, NULL, NULL, 0}
	};

	return (array);
}

t_fractal			*fractal_matcher(char *str)
{
	t_fractal	*f;
	int			i;

	f = get_fractal_const();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}
