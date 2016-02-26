/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:25:06 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/26 12:07:47 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ls_isflag(char c)
{
	if (c == 'l' || c == 'a' || c == 'r' || c == 'R' || c == 't')
		return (1);
	return (0);
}

static void			ls_fill_set(t_set *set, char c)
{
	if (c == 'l')
		set->flag = set->flag | 1;
	else if (c == 'R')
		set->flag = set->flag | 2;
	else if (c == 'r')
		set->flag = set->flag | 4;
	else if (c == 'a')
		set->flag = set->flag | 8;
	else if (c == 't')
		set->flag = set->flag | 16;
}

t_set				ls_parsing(char **arg, int count)
{
	t_set	set;
	int		i;
	int		j;

	set.flag = 0;
	set.folder = NULL;
	i = 1;
	j = 0;
	while (i < count && arg[i][j] == '-')
	{
		while (arg[i][j + 1])
		{
			j++;
			if (ls_isflag(arg[i][j]))
				ls_fill_set(&set, arg[i][j]);
			else
				ls_error(USAGE, NULL);
		}
		j = 0;
		i++;
	}
	fpf("%b\n", set.flag);
	return (set);
}
