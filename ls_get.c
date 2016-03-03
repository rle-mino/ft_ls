/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:42:40 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/03 20:40:06 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct stat		*get_stat(char *name)
{
	struct stat	*statbuff;

	statbuff = ft_memalloc(sizeof(struct stat));
	stat(name, statbuff);
	return (statbuff);
}

char			get_type(mode_t mode)
{
	//obtenir le char qui def le type
}

char			*get_right(t_file *file)
{
	char	*right;

	if (!(right = ft_memalloc(12)))
		ls_error(MALL_ERR, NULL);
	right[0] = get_type(file->stat->st_mode);
	return (right);
}
