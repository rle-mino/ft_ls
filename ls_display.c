/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 15:12:45 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/09 23:50:47 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_display(t_file *begin, t_set set)
{
	if (set.flag & 1)
	{
		if (!set.file)
			fpf("total %d\n", set.total);
		while (begin)
		{
			if (begin->name[0] == '.' && !(set.flag & 8))
				begin = begin->next;
			else
			{
				print_file(begin, set);
				begin = begin->next;
			}
		}
	}
	else
		while (begin)
		{
			if (*begin->name == '.' && !(set.flag & 8))
				begin = begin->next;
			else if (fpf("%s\n", begin->name))
				begin = begin->next;
		}
	return (1);
}

void			print_file(t_file *begin, t_set set)
{
	fpf("%s", get_right(begin));
	fpf(" %*d", set.lnl,begin->stat.st_nlink);
	fpf(" %-*s", set.lid, getpwuid(begin->stat.st_uid)->pw_name);
	fpf("  %-*s", set.lg + 1, getgrgid(begin->stat.st_gid)->gr_name);
	if (S_ISCHR(begin->stat.st_mode))
	{
		fpf("  %2d,", MAJOR(begin->stat.st_rdev));
		fpf(" %3d", MINOR(begin->stat.st_rdev));
	}
	else
		fpf(" %*d", set.lsi, begin->stat.st_size);
	adjust_t(begin->stat.st_mtime);
	fpf(" %s", begin->name);
	if (begin->symb)
		fpf(" -> %s\n", begin->symb);
	else
		fpf("\n");
}

void			adjust_t(time_t ti)
{
	int		ye;
	char	**tab;
	int		i;

	ye = ti - time(NULL) < -15552000 ? 8 : 7;
	ye = ti - time(NULL) > 3600 ? 8 : 7;
	tab = ft_strsplit(ctime(&ti), ' ');
	fpf(" %s %2s", tab[1], tab[2]);
	i = ft_strlen(tab[3]) - 1;
	while (i)
	{
		if (tab[3][i] == ':')
		{
			tab[3][i] = '\0';
			break ;
		}
		i--;
	}
	tab[4][ft_strlen(tab[4]) - 1] = '\0';
	fpf(" %5s", ye == 7 ? tab[3] : tab[4]);
}
