/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_display3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:00:12 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/14 22:39:13 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_size(off_t size, t_set set)
{
	if (set.flag & 256)
	{
		if (size > 1000000000000)
			fpf(" %d.%dT", size / 1000000000000, size % 10000000000);
		else if (size > 1000000000)
			fpf(" %d.%dG", size / 1000000000, size % 10000000);
		else if (size > 1000000)
			fpf(" %d.%dM", size / 1000000, size % 10000);
		else if (size > 1000 && size / 1000 < 100)
			fpf(" %d.%dK", size / 1000, size % 10);
		else if (size > 1000)
			fpf(" %dK", size / 1000);
		else
			fpf(" %3dB", size);
	}
	else
		fpf(" %*d", set.lsi, size);
}
