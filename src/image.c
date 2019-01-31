/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:35:34 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/31 15:07:12 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_image		*destroy_image(t_mlx *mlx, t_image *image)
{
	if (image != NULL)
	{
		if (image->img != NULL)
			mlx_destroy_image(mlx->mlx, image->img);
		ft_memdel((void **)&image);
	}
	return (NULL);
}

void		image_setpix(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(image->ptr + ((x + y * WIDTH) * image->bpp)) = color;
}

void		clear_image(t_image *image)
{
	ft_bzero(image->ptr, WIDTH * HEIGHT * image->bpp);
}

t_image		*new_image(t_mlx *mlx)
{
	t_image		*img;

	CHECK_NULL((img = ft_memalloc(sizeof(t_image))));
	if ((img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)) == NULL)
		return (destroy_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->img,
								&img->bpp,
								&img->stride,
								&img->endian);
	img->bpp /= 8;
	return (img);
}
