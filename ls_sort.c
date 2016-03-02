/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:41:22 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/02 22:53:06 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fold		*move_t(t_fold *x, long (*cmp)())
{
	t_fold		*n;
	t_fold		*p;
	t_fold		*ret;
	struct stat	a;
	struct stat	b;

	p = x;
	stat(x->name, &a);
	n = x->next;
	stat(n->name, &b);
	ret = n;
	while (n && cmp(a, b) < 0)
	{
		p = n;
		n = n->next;
		if (n)
			stat(n->name, &b);
	}
	p->next = x;
	x->next = n;
	return (ret);
}

t_fold		*sort_t(t_fold *start)
{
	struct stat	a;
	struct stat	b;

	if (start == NULL)
		return (NULL);
	start->next = sort_t(start->next);
	if (start->next)
	{
		stat(start->name, &a);
		stat(start->next->name, &b);
	}
	if (start->next && cmp_fold_time(a, b) < 0)
		start = move_t(start, cmp_fold_time);
	return (start);
}

void		ls_sort(t_fold **fold, t_set set)
{
	if (set.flag & 4 && set.flag & 16)
		*fold = sort_tr(*fold);
	else if (set.flag & 4)
		*fold = sort_r(*fold);
	else if (set.flag & 16)
		*fold = sort_t(*fold);
	show_me(*fold);
}
