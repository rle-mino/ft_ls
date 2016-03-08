/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:05:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/08 17:18:58 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <stdio.h>
# include <sys/acl.h>

# define DEBUG fpf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

enum
{
	ERRNO,
	O_NAME,
	O_ALL,
	ASCII,
	ASCII_REV,
	USAGE,
	MALL_ERR
};

typedef	struct stat		t_stat;

typedef struct			s_ls_file
{
	char				*name;
	char				*path;
	char				*symb;
	t_stat				stat;
	struct s_ls_file	*next;
}						t_file;

typedef struct			s_ls_fold
{
	char				*name;
	struct s_ls_fold	*next;
}						t_fold;

typedef struct			s_ls_set
{
	int					flag;
	int					lid;
	int					lg;
	int					lsi;
	int					lda;
	int					file;
	int					lnl;
	int					total;
}						t_set;

void					show_me(t_fold *fold);
void					show_me_arg(t_set set);
int						ft_ls(char *dir, t_set set);
int						ls_error(int error, char *str);
t_file					*stock_file(struct dirent *file, char *path);
void					ft_pushback(t_file **begin, t_file *link);
void					ft_push(t_file *begin, t_file *link, int cmp());
void					ft_pushback_fold(t_fold **begin, t_fold *link);
void					ft_push_fold(t_fold *begin, t_fold *link);
long					cmp_fold_time(struct stat a, struct stat b);
long					cmp_fold_name(t_fold *a, t_fold *b);
int						ls_display(t_file *begin, t_set set);
t_set					ls_parsing(char **arg, int count, t_fold **fold);
int						ls_isflag(char c);
t_fold					*stock_arg(char *name);
void					ls_init(t_fold **fold);
int						ls_master(t_fold **fold, t_set set);
void					ls_sort(t_fold **fold, t_set set);
t_fold					*sort_t(t_fold *start);
t_fold					*sort_r(t_fold *start);
t_fold					*sort_tr(t_fold *start);
long					cmp_rev_time(t_file *a, t_file *b);
long					cmp_time(t_file *a, t_file *b);
int						cmp_rev_name(t_file *a, t_file *b);
int						cmp_name(t_file *s1, t_file *s2);
char					*get_right(t_file *file);
void					print_file(t_file *begin, t_set set);
int						ft_nbrlen(long long nbr);
void					adjust_t(time_t ti);
int						ls_file(char *dir, t_set set);
void					ls_cmp(t_file **file, t_file *new, int (*cmp)());
t_file					*stock_file_arg(char *name, struct stat statb);
void					ls_filter(t_fold **fold, t_set *set);
void					free_files(t_file *files);
void					free_fold(t_fold *fold);
int						is_folder(char *name, t_stat *statb);
int						is_symb_lnk(char *link, t_stat *statl);
t_set					init_set_max(t_set set, t_file *begin, int lid, int lg);
void					*set_cmp(t_set set);

#endif
