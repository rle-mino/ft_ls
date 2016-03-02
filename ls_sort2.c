/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 22:32:59 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/02 22:52:20 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fold		*move_tr(t_fold *x, long (*cmp)())
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
	while (n && cmp(a, b) > 0)
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

t_fold		*sort_tr(t_fold *start)
{
	struct stat	a;
	struct stat	b;

	if (start == NULL)
		return (NULL);
	start->next = sort_tr(start->next);
	if (start->next)
	{
		stat(start->name, &a);
		stat(start->next->name, &b);
	}
	if (start->next && cmp_fold_time(a, b) > 0)
		start = move_tr(start, cmp_fold_time);
	return (start);
}

t_fold		*move_r(t_fold *x, int (*cmp)())
{
	t_fold	*n;
	t_fold	*p;
	t_fold	*ret;

	p = x;
	n = x->next;
	ret = n;
	while (n && cmp(x->name, n->name) < 0)
	{
		p = n;
		n = n->next;
	}
	p->next = x;
	x->next = n;
	return (ret);
}

t_fold		*sort_r(t_fold *start)
{
	if (start == NULL)
		return (NULL);
	start->next = sort_r(start->next);
	if (start->next && cmp_fold_name(start, start->next) < 0)
		start = move_r(start, ft_strcmp);
	return (start);
}
