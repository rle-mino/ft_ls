/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:05:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/23 23:11:21 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

# define IS_L & 1
# define IS_RUP & 2
# define IS_RLOW & 4
# define IS_A & 8
# define IS_T & 16
# define SET_L | 1
# define SET_RUP | 2
# define SET_RLOW | 4
# define SET_A | 8
# define SET_T | 16
# define ERRNO 0 
# define O_NAME 1
# define O_ALL 2
# define ASCII 1
# define ASCII_REV 2

typedef struct			s_ls_file
{
	char				*name;
	struct s_ls_file	*next;
}						t_ls_file;

void			ls_error(int error, char *dir);
t_ls_file		*stock_file(struct dirent *file, int info);
void			sort_ls_list(t_ls_file **files, int sequ);

#endif
