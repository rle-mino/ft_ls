/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 15:12:45 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/14 13:37:38 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			display_colors(t_file *link, t_set set)
{
	if (set.flag & 32)
	{
		if (S_ISLNK(link->stat.st_mode))
			fpf("%s%s%s", KMAG, link->name, RESET);
		else if (S_ISDIR(link->stat.st_mode))
			fpf("%s%s%s", KCYN, link->name, RESET);
		else if (S_ISSOCK(link->stat.st_mode))
			fpf("%s%s%s", KGRN, link->name, RESET);
		else if (S_IXUSR & link->stat.st_mode && S_ISUID ^ link->stat.st_mode)
			fpf("%s%s%s", KRED, link->name, RESET);
		else
			fpf("%s", link->name);
	}
	else
		fpf("%s", link->name);
	if (set.flag & 64 && S_ISDIR(link->stat.st_mode))
		fpf("/");
}

void			display_one(t_file *begin, t_set set)
{
	while (begin)
	{
		if (*begin->name == '.' && !(set.flag & 8))
			begin = begin->next;
		else
		{
			display_colors(begin, set);
			fpf("\n");
			begin = begin->next;
		}
	}
}

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
	else if (set.flag & 128)
		display_one(begin, set);
	else
		display_col(begin, set);
	return (1);
}

void			print_file(t_file *begin, t_set set)
{
	char	*tmp;

	fpf("%s", (tmp = get_right(begin)));
	free(tmp);
	fpf(" %*d", set.lnl, begin->stat.st_nlink);
	print_pwuid(begin, set);
	print_group(begin, set);
	if (S_ISCHR(begin->stat.st_mode))
	{
		fpf("  %2d,", MAJOR(begin->stat.st_rdev));
		fpf(" %3d", MINOR(begin->stat.st_rdev));
	}
	else
		fpf(" %*d", set.lsi, begin->stat.st_size);
	adjust_t(begin->stat.st_mtime);
	display_colors(begin, set);
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
	char	*tmp;

	ye = ti - time(NULL) < -15552000 ? 8 : 7;
	ye = ti - time(NULL) > 3600 ? 8 : 7;
	tmp = ctime(&ti);
	tab = ft_strsplit(tmp, ' ');
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
	fpf(" %5s ", ye == 7 ? tab[3] : tab[4]);
	free_tab(tab);
}
