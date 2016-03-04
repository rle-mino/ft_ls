/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:25:06 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/04 18:32:42 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int							ls_isflag(char c)
{
	if (c == 'l' || c == 'a' || c == 'r' || c == 'R' || c == 't')
		return (1);
	return (0);
}

static void					ls_fill_set(t_set *set, char c)
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

static int					ls_parsing_file(char **argv, int i, t_fold **fold,
																	int count)
{
	int		j;

	j = 0;
	if (argv[i][j] == '-' && argv[i][j + 1] == '-')
		i++;
	if (i < count)
		*fold = stock_arg(argv[i++]);
	while (i < count)
	{
		if (ft_strcmp(argv[i], (*fold)->name) < 0)
			ft_pushback_fold(fold, stock_arg(argv[i]));
		else
			ft_push_fold(*fold, stock_arg(argv[i]));
		i++;
	}
	return (0);
}

t_set						ls_parsing(char **arg, int count, t_fold **fold)
{
	t_set	set;
	int		i;
	int		j;

	set.flag = 0;
	i = 1;
	j = 0;
	while (i < count && arg[i][j] == '-')
	{
		if (arg[i][j] == '-' && arg[i][j + 1] == '-' && !(arg[i][j + 2]))
			break ;
		while (arg[i][j + 1])
		{
			j++;
			if (ls_isflag(arg[i][j]))
				ls_fill_set(&set, arg[i][j]);
			else
				ls_error(USAGE, arg[i]);
		}
		j = 0;
		i++;
	}
	if (i < count)
		ls_parsing_file(arg, i, fold, count);
	return (set);
}
