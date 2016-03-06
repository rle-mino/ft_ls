/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:54:35 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/06 17:22:58 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_set	set;
	t_fold	*fold;

	fold = NULL;
	set = ls_parsing(av, ac, &fold);
	if (fold && fold->next)
		ls_init(&fold);
	ls_master(&fold, set);
	return (0);
}
