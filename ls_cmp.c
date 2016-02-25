/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:27:41 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/25 19:09:53 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			cmp_name(t_file *s1, t_file *s2)
{
	int		i;

	i = 0;
	while (s1->name[i] == s2->name[i] && s1->name[i] && s2->name[i])
		i++;
	return ((unsigned char)s1->name[i] - (unsigned char)s2->name[i])
}
