/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 09:30:05 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/02 09:38:40 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		show_me(t_fold *fold)
{
	while (fold)
	{
		fpf("name = %s\n", fold->name);
		fold = fold->next;
	}
}

void		show_me_arg(t_set set)
{
	if (set.flag & 1)
		fpf("l:ON\n");
	if (set.flag & 2)
		fpf("R:ON\n");
	if (set.flag & 4)
		fpf("r:ON\n");
	if (set.flag & 8)
		fpf("a:ON\n");
	if (set.flag & 16)
		fpf("t:ON\n");
}
