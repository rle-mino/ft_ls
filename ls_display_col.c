/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 18:16:02 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/14 13:39:02 by rle-mino         ###   ########.fr       */
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

static void			display_col2(t_file **link, int *nb_col, t_set set)
{
	if (!(set.flag & 8) && (*link)->name[0] == '.')
		(*link) = (*link)->next;
	else
	{
		if ((*nb_col - 1) == 0)
			fpf("%s\n", (*link)->name);
		else
			fpf("%-*s", set.lname + 1, (*link)->name);
		*nb_col -= 1;
		(*link) = (*link)->next;
	}
}

void				display_col(t_file *link, t_set set)
{
	struct winsize	w;
	int				nb_col;
	int				bck;

	get_lname(&set, link);
	ioctl(0, TIOCGWINSZ, &w);
	if (set.lname)
		bck = w.ws_col / set.lname;
	else
		return ;
	while (link)
	{
		nb_col = bck;
		while (nb_col && link)
			display_col2(&link, &nb_col, set);
	}
	fpf("\n");
}
