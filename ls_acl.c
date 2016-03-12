/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_acl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 20:50:38 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/12 23:36:08 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		ls_get_acl(t_file *link)
{
	char	*tmp;
	acl_t	tmp2;
	char	tmp3[101];

	tmp = ft_strjoin(link->path, link->name);
	if (listxattr(tmp, tmp3, sizeof(tmp3), XATTR_NOFOLLOW) > 0)
	{
		free(tmp);
		return ('@');
	}
	if ((tmp2 = acl_get_file(tmp, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp2);
		free(tmp);
		return ('+');
	}
	free(tmp);
	return (' ');
}
