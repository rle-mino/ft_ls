/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:54:35 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/26 11:27:48 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_set	ls;

	if (ac == 1)
		return (ft_ls("."));
	else
		ls = ls_parsing(av, ac);
	return (0);
}
