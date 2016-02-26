/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:05:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/26 11:32:26 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <stdio.h>

# define DEBUG fpf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

enum
{
	ERRNO,
	O_NAME,
	O_ALL,
	ASCII,
	ASCII_REV,
	USAGE
};

typedef struct			s_ls_file
{
	char				*name;
	struct s_ls_file	*next;
}						t_file;

typedef struct			s_ls_set
{
	long				flag;
	char				*folder;
}						t_set;

int						ft_ls(char *dir);
int						ls_error(int error, char *dir);
t_file					*stock_file(struct dirent *file, int info);
void					ft_pushback(t_file **begin, t_file *link);
void					ft_push_name(t_file *begin, t_file *link, int cmp());
int						cmp_name(t_file *s1, t_file *s2);
void					ls_display(t_file *begin, int info);
t_set					ls_parsing(char **arg, int count);

#endif
