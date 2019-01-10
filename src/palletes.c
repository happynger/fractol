/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palletes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:45:29 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/09 16:52:16 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include <stddef.h>

t_pallete	*get_palletes(void)
{
	static t_pallete	array[10];

	array[0] =
		(t_pallete){5, 0, {0x25064C, 0x36175E, 0x553285, 0x7B52AB, 0x9768D1}};
	array[1] =
		(t_pallete){5, 0, {0xCE00E8, 0xF50C3C, 0xFF0EB8, 0xA20DFF, 0x5C0CF5}};
	array[2] =
		(t_pallete){5, 0, {0x9232FF, 0xF50CDC, 0x001BE8, 0x23BAFF, 0x0CF5B5}};
	array[3] =
		(t_pallete){5, 0, {0x6429F5, 0x33CFE8, 0x6A96FF, 0x5BFFB3, 0x52F541}};
	array[4] =
		(t_pallete){5, 0, {0x332532, 0x644D52, 0xF77A52, 0xFF974F, 0xA49A87}};
	array[5] =
		(t_pallete){5, 0, {0x96CA2D, 0xB5E655, 0xEDF7F2, 0x4BB5C1, 0x7FC6BC}};
	array[6] = (t_pallete){0, 0, {0}};
	return (array);
}
