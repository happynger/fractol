/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:49:35 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/06 13:09:24 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_tabmin(int **tab, int xmax, int ymax)
{
	int		j;
	int		i;
	int		min;

	min = INT_MAX;
	i = -1;
	j = -1;
	while (++i < ymax)
	{
		while (++j < xmax)
			if (tab[i][j] < min)
				min = tab[i][j];
		j = -1;
	}
	return (min);
}
