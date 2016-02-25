/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:05:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/25 19:24:51 by rle-mino         ###   ########.fr       */
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

# define DEBUG fpf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

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

enum
{
	ERRNO,
	O_NAME,
	O_ALL,
	ASCII,
	ASCII_REV
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
void					ls_error(int error, char *dir);
t_file					*stock_file(struct dirent *file, int info);
void					ft_pushback(t_file **begin, t_file *link);
void					ft_push_name(t_file *begin, t_file *link, int cmp());
int						cmp_name(t_file *s1, t_file *s2);
void					ls_display(t_file *begin, int info);
t_set					ls_parsing(char **arg);

#endif
