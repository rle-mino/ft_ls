/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:05:58 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/14 22:53:32 by rle-mino         ###   ########.fr       */
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
# include <sys/xattr.h>
# include <sys/ioctl.h>

# define MINORBITS       24
# define MINORMASK       (0xffffff)
# define MAJOR(dev)      ((unsigned int) ((dev) >> MINORBITS))
# define MINOR(dev)      ((unsigned int) ((dev) & MINORMASK))
# define MKDEV(ma,mi)    (((ma) << MINORBITS) | (mi))
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define RESET "\033[0m"

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
typedef struct dirent	t_dirent;

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
	char				*path;
	struct s_ls_fold	*next;
}						t_fold;

typedef struct			s_ls_set
{
	long				flag;
	int					lid;
	int					lg;
	int					lsi;
	int					lda;
	int					lname;
	int					nbfile;
	int					file;
	int					lnl;
	int					total;
}						t_set;

int						ft_ls(char *dir, t_set set);
int						ls_error(int error, char *str);
void					ft_pushback(t_file **begin, t_file *link);
void					ft_push(t_file *begin, t_file *link, int cmp());
void					ft_pushback_fold(t_fold **begin, t_fold *link);
void					ft_push_fold(t_fold *begin, t_fold *link);
long					cmp_fold_time(struct stat a, struct stat b);
long					cmp_fold_name(t_fold *a, t_fold *b);
int						ls_display(t_file *begin, t_set set);
void					print_pwuid(t_file *begin, t_set set);
void					print_group(t_file *begin, t_set set);
t_set					ls_parsing(char **arg, int count, t_fold **fold);
int						ls_isflag(char c);
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
int						no_cmp(t_file *s1, t_file *s2);
char					*get_right(t_file *file);
void					print_file(t_file *begin, t_set set);
int						ft_nbrlen(long long nbr);
void					adjust_t(time_t ti);
int						ls_file(char *dir, t_set set);
void					ls_cmp(t_file **file, t_file *new, int (*cmp)());
t_file					*stock_file_arg(char *name, struct stat statb);
t_fold					*stock_arg(char *name);
t_file					*stock_file(struct dirent *file, char *path);
t_fold					*stock_fold(char *name, char *path);
t_file					*stk_dir(t_dirent *file, char *path);
void					ls_filter(t_fold **fold, t_set *set);
void					free_files(t_file *files);
void					free_fold(t_fold *fold);
void					free_tab(char **tab);
int						is_folder(char *name, t_stat *statb);
int						is_symb_lnk(char *link, t_stat *statl);
int						is_directory(struct dirent *file, t_file *fold,
																t_set set);
t_set					init_set_max(t_set set, t_file *begin);
void					*set_cmp(t_set set);
int						*ls_recu(t_file *fold, t_set set);
t_file					*get_next_fold(t_file *fold, t_set set);
t_file					*ls_conv(t_fold *fold);
char					ls_get_acl(t_file *link);
void					display_col(t_file *link, t_set set);
void					display_size(off_t size, t_set set);

#endif
