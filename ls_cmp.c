/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:27:41 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/04 13:50:04 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			cmp_name(t_file *s1, t_file *s2)
{
	int		i;

	i = 0;
	while (s1->name[i] == s2->name[i] && s1->name[i] && s2->name[i])
		i++;
	return ((unsigned char)s1->name[i] - (unsigned char)s2->name[i]);
}

long		cmp_fold_time(struct stat a, struct stat b)
{
	return (a.st_mtime - b.st_mtime);
}

long		cmp_fold_name(t_fold *a, t_fold *b)
{
	return ((long)ft_strcmp(a->name, b->name));
}

int			cmp_rev_time(t_file *a, t_file *b)
{
	return (b->stat->st_mtime - a->stat->st_mtime);
}

int			cmp_time(t_file *a, t_file *b)
{
	return (a->stat->st_mtime - b->stat->st_mtime);
}
