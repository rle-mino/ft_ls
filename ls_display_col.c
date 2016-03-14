/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:16:02 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/14 18:23:24 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			get_lname(t_set *set, t_file *link)
{
	int		a;

	a = 0;
	set->lname = 0;
	set->nbfile = 0;
	while (link)
	{
		if (!(set->flag & 8) && link->name[0] == '.')
			link = link->next;
		else
		{
			a = ft_strlen(link->name);
			set->lname = set->lname < a ? a : set->lname;
			link = link->next;
			set->nbfile++;
		}
	}
}

static void			display_col_colors_n(t_file *link, t_set set)
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
	fpf("\n");
}

static void			display_col_colors(t_file *link, t_set set)
{
	int		a;

	a = set.lname + 1;
	if (set.flag & 32)
	{
		if (S_ISLNK(link->stat.st_mode))
			fpf("%s%-*s%s", KMAG, a, link->name, RESET);
		else if (S_ISDIR(link->stat.st_mode))
			fpf("%s%-*s%s", KCYN, a, link->name, RESET);
		else if (S_ISSOCK(link->stat.st_mode))
			fpf("%s%-*s%s", KGRN, a, link->name, RESET);
		else if (S_IXUSR & link->stat.st_mode && S_ISUID ^ link->stat.st_mode)
			fpf("%s%-*s%s", KRED, a, link->name, RESET);
		else
			fpf("%-*s", a, link->name);
	}
	else
	{
		fpf("%-*s", a, link->name);
	}
	if (set.flag & 64 && S_ISDIR(link->stat.st_mode))
		fpf("/");
}

static void			display_col2(t_file **link, t_set set, int bck)
{
	int	nb_col;

	nb_col = bck;
	while (nb_col && *link)
	{
		if (!(set.flag & 8) && (*link)->name[0] == '.')
			(*link) = (*link)->next;
		else
		{
			if ((nb_col - 1) == 0)
			{
				display_col_colors_n(*link, set);
			}
			else
				display_col_colors(*link, set);
			nb_col -= 1;
			(*link) = (*link)->next;
		}
	}
}

void				display_col(t_file *link, t_set set)
{
	struct winsize	w;
	int				bck;

	get_lname(&set, link);
	ioctl(0, TIOCGWINSZ, &w);
	if (set.lname)
		bck = w.ws_col / set.lname;
	else
		return ;
	while (link)
		display_col2(&link, set, bck);
	fpf("\n");
}
