/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:31:40 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/14 22:29:09 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_pwuid(t_file *begin, t_set set)
{
	struct passwd	*pwd;

	if (!(set.flag & 512))
	{
		if ((pwd = getpwuid(begin->stat.st_uid)))
			fpf(" %-*s", set.lid, pwd->pw_name);
		else
			fpf(" %-*s", set.lid, " ");
	}
}

void		print_group(t_file *begin, t_set set)
{
	struct group	*grp;

	if (!(set.flag & 2048))
	{
		if ((grp = getgrgid(begin->stat.st_gid)))
			fpf("  %-*s", set.lg + 1, grp->gr_name);
		else
			fpf("  %-*s", set.lg, " ");
	}
}
