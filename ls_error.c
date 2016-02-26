/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:08:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/26 18:46:01 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_error(int error, char *dir)
{
	if (errno == EACCES)
	{
		ft_putstr_fd(dir, 2);
		perror(strerror(errno));
	}
	else if (error == USAGE)
	{
		perror("ft_ls: illegal option\n");
		perror("Usage : ./ft_ls [-Ralrt] [file ...]");
		exit(0);
	}
	else if (error == MALL_ERR)
	{
		perror(strerror(errno));
		exit(0);
	}
	return (0);
}
