/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 19:31:01 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/02 09:55:52 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fold		*stock_arg(char *name)
{
	t_fold		*fold;

	if (!(fold = ft_memalloc(sizeof(t_fold))))
		ls_error(MALL_ERR, NULL);
	fold->name = name;
	fold->next = NULL;
	return (fold);
}

void		ft_pushback_fold(t_fold **begin, t_fold *link)
{
	link->next = *begin;
	*begin = link;
}

void		ft_push_fold(t_fold *begin, t_fold *link)
{
	t_fold	*tmp;

	tmp = begin;
	while (tmp->next)
	{
		if (tmp->next && ft_strcmp(tmp->next->name, link->name) >= 0)
		{
			link->next = tmp->next;
			tmp->next = link;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = link;
}
