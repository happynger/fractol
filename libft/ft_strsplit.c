/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:53:20 by otahirov          #+#    #+#             */
/*   Updated: 2019/01/05 16:56:05 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_split_count(char const *s, char c)
{
	int	i;
	int	d;
	int	wrd;

	i = 0;
	d = 0;
	wrd = 0;
	while (s[i])
	{
		if (s[i++] != c)
		{
			if (d == 0)
			{
				d = 1;
				wrd++;
			}
		}
		else
			d = 0;
	}
	return (wrd);
}

static int		ft_split_len(char const *s, char c, int cword)
{
	int	i;
	int	d;
	int	wrd;
	int	len;

	len = 0;
	i = 0;
	d = 0;
	wrd = 0;
	while (s[i])
		if (s[i++] != c)
		{
			if (d == 0)
			{
				d = 1;
				wrd++;
			}
			if (d == 1 && wrd == cword)
				len++;
		}
		else
			d = 0;
	return (len);
}

static int		ft_split_start(char const *s, char c, int cword)
{
	int	i;
	int	d;
	int	wrd;
	int	len;

	len = 0;
	i = 0;
	d = 0;
	wrd = 0;
	while (s[i])
		if (s[i++] != c)
		{
			if (d == 0)
			{
				d = 1;
				wrd++;
				if (wrd == cword)
					return (i - 1);
			}
		}
		else
			d = 0;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		wrd;
	int		i;
	int		start;
	int		len;

	if (s == NULL)
		return (NULL);
	wrd = ft_split_count(s, c);
	if (!(tab = malloc(sizeof(char*) * (wrd + 1))))
		return (NULL);
	i = 0;
	while (i < wrd)
	{
		start = ft_split_start(s, c, i + 1);
		len = ft_split_len(s, c, i + 1);
		tab[i] = ft_strsub(s, (unsigned int)start, (size_t)len);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
