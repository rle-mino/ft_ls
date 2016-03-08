/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 19:11:30 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/08 17:36:41 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

t_file		*stock_file_arg(char *name, struct stat statb)
{
	t_file		*file;
	struct stat	statl;

	file = ft_memalloc(sizeof(t_file));
	file->name = ft_strdup(name);
	file->stat = statb;
	if (!(lstat(file->name, &statl)) && S_ISLNK(statl.st_mode))
	{
		file->stat = statl;
		file->symb = ft_memalloc(statl.st_size + 1);
		readlink(file->name, file->symb, statl.st_size);
	}
	else
		file->symb = NULL;
	file->path = NULL;
	file->next = NULL;
	return (file);
}
