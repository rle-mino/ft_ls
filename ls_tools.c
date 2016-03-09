/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 19:31:01 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/09 11:31:17 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_init(t_fold **fold)
{
	struct stat		statbuf;
	t_fold			*tmp;
	t_fold			*bck;

	while (*fold && stat((*fold)->name, &statbuf) == -1)
	{
		tmp = *fold;
		ls_error(ERRNO, (*fold)->name);
		*fold = (*fold)->next;
		free(tmp);
	}
	bck = *fold;
	while (bck && bck->next)
	{
		if (stat(bck->next->name, &statbuf) == -1)
		{
			tmp = bck->next;
			ls_error(ERRNO, bck->next->name);
			bck->next = bck->next->next ? bck->next->next : NULL;
			free(tmp);
		}
		else
			bck = bck->next;
	}
}

int			ft_nbrlen(long long nbr)
{
	int		i;

	i = 0;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i + 1);
}
