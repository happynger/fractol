/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 12:43:03 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/06 13:09:08 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_tabmax(int **tab, int xmax, int ymax)
{
	int	max;
	int	i;
	int	j;

	max = INT_MIN;
	i = -1;
	j = -1;
	while (++i < ymax)
	{
		while (++j < xmax)
			if (tab[i][j] > max)
				max = tab[i][j];
		j = -1;
	}
	return (max);
}
