/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:25:06 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/26 10:10:06 by rle-mino         ###   ########.fr       */
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
		set->flag = set->flag SET_L;
	else if (c == 'R')
		set->flag = set->flag SET_RUP;
	else if (c == 'r')
		set->flag = set->flag SET_RLOW;
	else if (c == 'a')
		set->flag = set->flag SET_A;
	else if (c == 't')
		set->flag = set->flag SET_T;
}

t_set		ls_parsing(char **arg, int count)
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
		while (arg[i][j])
		{
			if (ls_isflag(arg[i][j]))
				ls_fill_set(&set, arg[i][j]);
			else
				return (ls_error(USAGE, NULL));
			j++;
		}
		i++;
	}
	return (set);
}
