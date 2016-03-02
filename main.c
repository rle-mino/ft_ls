/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:54:35 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/02 12:27:04 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_set	set;
	t_fold	*fold;

	if (ac == 1)
		return (ft_ls("."));
	else
		set = ls_parsing(av, ac, &fold);
	ls_init(&fold);
	show_me(fold);
	return (0);
}
