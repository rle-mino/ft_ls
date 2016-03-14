/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 15:08:23 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/14 22:11:32 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		init_set(t_set *set)
{
	set->lid = 0;
	set->lg = 0;
	set->lsi = 0;
	set->lda = 0;
	set->total = 0;
	set->lnl = 0;
}

void		init_set_max2(t_set *set, t_file **begin)
{
	int	ta[2];
	int	lid;
	int	lg;

	ta[0] = 0;
	ta[1] = 0;
	lid = 0;
	lg = 0;
	if (getpwuid((*begin)->stat.st_uid))
		lid = ft_strlen(getpwuid((*begin)->stat.st_uid)->pw_name);
	if (getgrgid((*begin)->stat.st_gid))
		lg = ft_strlen(getgrgid((*begin)->stat.st_gid)->gr_name);
	ta[1] = ft_strlen(ctime(&(*begin)->stat.st_mtime));
	ta[0] = ft_nbrlen((*begin)->stat.st_size);
	set->lnl = set->lnl < ft_nbrlen((*begin)->stat.st_nlink) ?
		ft_nbrlen((*begin)->stat.st_nlink) : set->lnl;
	set->lid = lid > set->lid ? lid : set->lid;
	set->lg = lg > set->lg ? lg : set->lg;
	set->lsi = ta[0] > set->lsi ? ta[0] : set->lsi;
	set->lda = ta[1] > set->lda ? ta[1] : set->lda;
	set->total += (*begin)->stat.st_blocks;
	*begin = (*begin)->next;
}

t_set		init_set_max(t_set set, t_file *begin)
{
	init_set(&set);
	while (begin)
	{
		if (!(set.flag & 8) && begin->name[0] == '.')
			begin = begin->next;
		else
			init_set_max2(&set, &begin);
	}
	return (set);
}

void		*set_cmp(t_set set)
{
	if (set.flag & 4 && set.flag & 16)
		return (void*)cmp_rev_time;
	else if (set.flag & 16)
		return (void*)cmp_time;
	else if (set.flag & 4)
		return (void*)cmp_rev_name;
	else if (set.flag & 1024)
		return (void*)no_cmp;
	else
		return (void*)cmp_name;
}
