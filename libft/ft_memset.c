/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:13:23 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/05 12:58:25 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	tmp2;
	size_t			i;

	tmp1 = (unsigned char *)b;
	tmp2 = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		tmp1[i] = tmp2;
		i++;
	}
	return (tmp1);
}
