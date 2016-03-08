/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:42:40 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/08 15:29:58 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			get_type(mode_t mode)
{
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISREG(mode))
		return ('-');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISSOCK(mode))
		return ('s');
	return ('?');
}

char			get_r_user(mode_t mode)
{
	if (S_IXUSR & mode && S_ISUID & mode)
		return ('s');
	if (S_IXUSR & mode && S_ISUID ^ mode)
		return ('x');
	if (S_IXUSR ^ mode && S_ISUID & mode)
		return ('S');
	return ('-');
}

char			get_r_grp(mode_t mode)
{
	if (S_IXGRP & mode && S_ISGID & mode)
		return ('s');
	if (S_IXGRP & mode && S_ISGID ^ mode)
		return ('x');
	if (S_IXGRP ^ mode && S_ISGID & mode)
		return ('S');
	return ('-');
}

char			get_r_oth(mode_t mode)
{
	if (S_IXOTH & mode && S_ISVTX & mode)
		return ('t');
	if (S_IXOTH & mode && S_ISVTX ^ mode)
		return ('x');
	if (S_IXOTH ^ mode && S_ISVTX & mode)
		return ('T');
	return ('-');
}

char			*get_right(t_file *file)
{
	char	*right;
	mode_t	mode;

	mode = file->stat.st_mode;
	if (!(right = ft_memalloc(12)))
		ls_error(MALL_ERR, NULL);
	right[0] = get_type(mode);
	right[1] = S_IRUSR & mode ? 'r' : '-';
	right[2] = S_IWUSR & mode ? 'w' : '-';
	right[3] = get_r_user(mode);
	right[4] = S_IRGRP & mode ? 'r' : '-';
	right[5] = S_IWGRP & mode ? 'w' : '-';
	right[6] = get_r_grp(mode);
	right[7] = S_IROTH & mode ? 'r' : '-';
	right[8] = S_IWOTH & mode ? 'w' : '-';
	right[9] = get_r_oth(mode);
	right[10] = ' ';
	return (right);
}
