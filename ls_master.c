/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_master.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:26:12 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/05 20:58:44 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_master(t_fold **fold, t_set set)
{
	ls_filter(fold, set);
	if (set.flag & 4 || set.flag & 16)
		ls_sort(fold, set);
	if (set.flag & 2)
		exit(0);
	if (!(*fold))
		ft_ls(".", set);
	else
		while (*fold)
		{
			fpf("%s:\n", (*fold)->name);
			ft_ls((*fold)->name, set);
			*fold = (*fold)->next;
		}
	return (0);
}
