/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conv_j.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:51:48 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/08 06:44:26 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			octal_prec_j(t_struct data, uintmax_t nbr, int i)
{
	int		k;

	k = 0;
	k += put_prec_nbr(data.prec - i);
	if (data.flag & 1)
		k += pf_putchar('0');
	if (data.prec != -1)
		pf_putoctal_noflag_j(nbr);
	return (k);
}

static int			octal_min_j(t_struct data, uintmax_t nbr, int i)
{
	int		j;
	int		k;
	int		l;

	l = data.flag & 1 ? 2 : 0;
	k = 0;
	j = i;
	if (data.flag & 1 && data.min != 0 && data.flag & 2)
	{
		if (data.flag & 1 && nbr != 0)
			k += pf_putchar('0');
		while (k < data.min - (data.prec < j ? 0 : data.prec))
			k += pf_putchar(data.flag & 2 ? '0' : ' ');
	}
	else
	{
		while (k < data.min - (data.prec < j ? j : data.prec))
			k += pf_putchar(data.flag & 2 ? '0' : ' ');
		if (data.flag & 1 && nbr != 0)
			k += pf_putchar('0');
	}
	k += put_prec_nbr(data.prec - j);
	if (data.prec != -1 || nbr != 0)
		pf_putoctal_noflag_j(nbr);
	return (k);
}

static int			octal_hash_j(t_struct data, uintmax_t nbr, int i)
{
	int		j;
	int		k;

	k = 0;
	j = i;
	if (data.flag & 1 && nbr != 0)
		k += pf_putchar('0');
	k += put_prec_nbr(data.prec - j);
	if (data.prec != -1)
		pf_putoctal_noflag_j(nbr);
	while (k < data.min + (data.flag & 1 ? 2 : 0) - j)
		k += pf_putchar(' ');
	return (k);
}

int					octal_conv_j(t_struct data, uintmax_t nbr)
{
	int		i;
	int		k;

	k = 0;
	i = pf_retoctal_j(nbr, 2);
	if (nbr == 0 && data.min != 0)
		i = 0;
	data.min = data.flag & 1 ? data.min - 2 : data.min;
	if (data.flag & 4 && data.min != 0)
		k = octal_hash_j(data, nbr, i);
	else if (data.min != 0)
		k = octal_min_j(data, nbr, i);
	else
		k = octal_prec_j(data, nbr, i);
	if (data.prec != -1 || nbr != 0)
		return (k + i);
	return (k);
}
