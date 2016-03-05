/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:27:41 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/05 11:44:14 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				cmp_name(t_file *s1, t_file *s2)
{
	int		i;

	i = 0;
	while (s1->name[i] == s2->name[i] && s1->name[i] && s2->name[i])
		i++;
	return ((unsigned char)s1->name[i] - (unsigned char)s2->name[i]);
}

long			cmp_fold_time(struct stat a, struct stat b)
{
	return (a.st_mtime - b.st_mtime);
}

long			cmp_fold_name(t_fold *a, t_fold *b)
{
	return ((long)ft_strcmp(a->name, b->name));
}

long			cmp_rev_time(t_file *a, t_file *b)
{
	long	a_a;
	long	b_b;

	a_a = a->stat.st_mtime + a->stat.st_mtimespec.tv_nsec;
	b_b = b->stat.st_mtime + b->stat.st_mtimespec.tv_nsec;
	return (a_a - b_b);
}

long			cmp_time(t_file *a, t_file *b)
{
	long	a_a;
	long	b_b;

	a_a = a->stat.st_mtime;
	b_b = b->stat.st_mtime;
	if (a_a == b_b)
		return (b->stat.st_mtimespec.tv_nsec - a->stat.st_mtimespec.tv_nsec);
	return (b_b - a_a);
}
