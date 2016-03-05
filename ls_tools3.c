/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 19:11:30 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/05 19:14:32 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_nbrlen(long long nbr)
{
	int		i;

	i = 0;
	while (nbr > 10)
	{
		nbr /= 10;
		i++;
	}
	return (i + 1);
}

void		adjust_t(time_t ti)
{
	int		ye;
	char	**tab;
	int		i;

	ye = ti - time(NULL) < -31536000 ? 8 : 7;
	tab = ft_strsplit(ctime(&ti), ' ');
	fpf(" %s %2s", tab[1], tab[2]);
	i = ft_strlen(tab[3]) - 1;
	while (i)
	{
		if (tab[3][i] == ':')
		{
			tab[3][i] = '\0';
			break ;
		}
		i--;
	}
	tab[4][ft_strlen(tab[4]) - 1] = '\0';
	fpf(" %5s", ye == 7 ? tab[3] : tab[4]);
}

t_file		*stock_file_arg(char *name, struct stat statb)
{
	t_file	*file;

	file = ft_memalloc(sizeof(t_file));
	file->name = name;
	file->stat = statb;
	file->path = NULL;
	file->next = NULL;
	return (file);
}
