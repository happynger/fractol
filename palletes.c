/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palletes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:45:29 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/08 19:50:08 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_pallete	*get_palletes(void)
{
	static t_pallete	array[5];

	array[0] =
		(t_pallete){5, 0, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	array[1] = (t_pallete){0, 0, {0}};
	return (array);
}
