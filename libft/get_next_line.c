/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:05:40 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/08 17:53:32 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static char	*join(char *buff, char *tab)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (buff)
		i = ft_strlen(buff);
	if (tab)
		j = ft_strlen(tab);
	ptr = (char *)malloc(sizeof(char) * (i + j + 1));
	ft_memcpy(ptr, buff, i);
	ft_memcpy(ptr + i, tab, j);
	ptr[i + j] = '\0';
	free(buff);
	ft_bzero(tab, BUFF_SIZE + 1);
	return (ptr);
}

static int	endline(char *buff)
{
	int		counter;

	counter = 0;
	while (buff[counter] != ENDL && buff[counter])
		counter++;
	if (buff[counter] == ENDL)
	{
		buff[counter] = END;
		return (counter);
	}
	else
		return (-1);
}

static int	verify(char **buff, char **tab, char **line)
{
	char	*ptr;
	int		finale;

	*buff = join(*buff, *tab);
	finale = endline(*buff);
	if (finale > -1)
	{
		*line = ft_strdup(*buff);
		ptr = *buff;
		*buff = ft_strdup(*buff + finale + 1);
		free(ptr);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buff[256];
	char		*tmp;
	int			ret;
	int			result;

	tmp = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		result = verify(&buff[fd], &tmp, line);
		free(tmp);
		if (result == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if ((result = verify(&buff[fd], &tmp, line)))
		return (1);
	else if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	return (result);
}
