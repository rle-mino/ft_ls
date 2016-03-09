/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:26:12 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/09 23:56:16 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		init_fold(t_fold **fold)
{
	if (*fold)
		return ;
	if (!(*fold = ft_memalloc(sizeof(t_fold))))
		ls_error(MALL_ERR, NULL);
	(*fold)->name = ft_strdup("./");
	(*fold)->path = (*fold)->name;
	(*fold)->next = NULL;
}

int			ls_master(t_fold **fold, t_set set)
{
	ls_filter(fold, &set);
	if (set.flag & 4 || set.flag & 16)
		ls_sort(fold, set);
	if (set.flag & 2)
	{
		init_fold(fold);
		while (*fold)
		{
			ft_ls((*fold)->name, set);
			ls_recu(get_next_fold(ls_conv(*fold), set), set);
			*fold = (*fold)->next;
		}
	}
	else if (!(*fold) && !(set.file))
		ft_ls(".", set);
	else
		while (*fold)
		{
			if ((set.file))
				fpf("\n%s:\n", (*fold)->name);
			if (!set.file && (*fold)->next && (set.file = 1))
				fpf("%s:\n", (*fold)->name);
			ft_ls((*fold)->name, set);
			*fold = (*fold)->next;
		}
	return (0);
}
