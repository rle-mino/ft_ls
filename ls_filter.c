/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 20:41:04 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/14 13:50:20 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_file(t_fold *bck, t_file **files, t_set set)
{
	t_fold		*tmp;
	t_stat		stat;
	t_stat		statl;

	while (bck && bck->next)
	{
		if (!is_folder(bck->name, &stat) ||
				(is_symb_lnk(bck->name, &statl) && set.flag & 1))
		{
			tmp = bck->next;
			if (!(*files))
				(*files) = stock_file_arg(bck->next->name, stat);
			else
				ls_cmp(files, stock_file_arg(bck->next->name, stat),
															set_cmp(set));
			bck->next = bck->next->next;
			free(tmp);
		}
		else
			bck = bck->next;
	}
}

void		ls_filter(t_fold **fold, t_set *set)
{
	t_stat			stat;
	t_stat			statl;
	t_fold			*tmp;
	t_fold			*bck;
	t_file			*files;

	files = NULL;
	set->file = 0;
	while (*fold && (!is_folder((*fold)->name, &stat) ||
			(is_symb_lnk((*fold)->name, &statl) && set->flag & 1)))
	{
		tmp = *fold;
		if (!files)
			files = stock_file_arg((*fold)->name, stat);
		else
			ls_cmp(&files, stock_file_arg((*fold)->name, stat),
															set_cmp(*set));
		*fold = (*fold)->next;
		free_fold(tmp);
	}
	bck = *fold;
	get_file(bck, &files, *set);
	*set = init_set_max(*set, files);
	if (files && (set->file = 1) && ls_display(files, *set))
		free_files(files);
}
