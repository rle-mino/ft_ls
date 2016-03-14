/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:08:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/14 22:35:48 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_ill(char *str)
{
	int		i;

	i = 0;
	if ((str[i]) == '-')
		i++;
	while (ls_isflag(str[i]))
		i++;
	ft_putchar(str[i]);
}

void		errno_display(char *str)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
}

int			ls_error(int error, char *str)
{
	if (error == ERRNO)
		errno_display(str);
	else if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		get_ill(str);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("Usage : ./ft_ls [-1RGafghloprt] [file ...]\n", 2);
		exit(0);
	}
	else if (error == MALL_ERR)
	{
		perror(strerror(errno));
		exit(0);
	}
	return (0);
}
