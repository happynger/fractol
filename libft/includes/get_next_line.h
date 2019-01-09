/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:31:15 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/05 12:30:41 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024

# ifndef LIBFT_H
#  include "./libft.h"
# endif

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif
