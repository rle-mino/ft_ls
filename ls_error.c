/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:08:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/02 10:31:30 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_ill(char *dir)
{
	int		i;

	i = 0;
	if ((dir[i]) == '-')
		i++;
	while (ls_isflag(dir[i]))
		i++;
	ft_putchar(dir[i]);
}

int			ls_error(int error, char *dir)
{
	if (errno == EACCES)
	{
		ft_putstr_fd(dir, 2);
		perror(strerror(errno));
	}
	else if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		get_ill(dir);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("Usage : ./ft_ls [-Ralrt] [file ...]\n", 2);
		exit(0);
	}
	else if (error == MALL_ERR)
	{
		perror(strerror(errno));
		exit(0);
	}
	return (0);
}
