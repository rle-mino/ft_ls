/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:26:12 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/08 20:58:26 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_master(t_fold **fold, t_set set)
{
	ls_filter(fold, &set);
	if (set.flag & 4 || set.flag & 16)
		ls_sort(fold, set);
	if (set.flag & 2)
		while (*fold)
		{
			ls_recu(*fold, set);
			*fold = (*fold)->next;
		}
	if (!(*fold) && !(set.file))
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
