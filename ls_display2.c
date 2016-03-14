/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:31:40 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/14 13:57:26 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_pwuid(t_file *begin, t_set set)
{
	if (getpwuid(begin->stat.st_uid))
		fpf(" %-*s", set.lid, getpwuid(begin->stat.st_uid)->pw_name);
	else
		fpf(" %-*s", set.lid, " ");
}

void		print_group(t_file *begin, t_set set)
{
	if (getgrgid(begin->stat.st_gid))
		fpf("  %-*s", set.lg + 1, getgrgid(begin->stat.st_gid)->gr_name);
	else
		fpf("  %-*s", set.lg, " ");
}
