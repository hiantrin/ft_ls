/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 02:40:51 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/23 18:51:34 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# define BUFF_SIZE	1000

void	print_my_ls(char *flag, char **str, char *path);
void	remplir_a(char **str, char *path);
void	remplir(char **str, char *path);
void	true_place(char **str);
void	true_time(char **str, char **tim);
void	print_usr(mode_t st_mode, char **perm);
void	print_grp(mode_t st_mode, char **perm);
void	print_oth(mode_t st_mode, char **perm);
void	ls_rr(char **str, char *path, char *flag, char **name);
void	print_type(mode_t st_mode, char *perm);
char	**make_my_lyst(char *p, char *str, int max, struct stat l);
void	print_major_minor(char *maj, char *min, int max, char *str);
void	ls_rr_help(char *new, char *name, char *flag, char *p);
void	free_3d(char ***str);
void	free_2d(char **str);
void	ls_time(char **str, char *path);
void	print_dir(char **mine, int a, char *c, char *flag);
void	help_dir(char *mine, char *flag, char *new, char *c);
void	help_for_print(char	**real, char **name, char *flag);
void	create_flag(char *flag, char *str, char *c);
void	help_lien(char *str, char *mine, char *flag);
void	transfer_to_myls(char *flag, char **str, char *c);
void	concate_flag(char *flag, char *c, char **str);

int		n_str_a(char *path);
int		n_str(char *path);
int		my_time(char *str, char *mine);
int		cloc(char *str);
int		day(char *str);
int		month_to_num(char *str);
int		lenght(char ***my_list, int j);
int		compare_year(struct stat l);
int		major_num(char **str, char *path);
int		year(char *str);
int		month(char *str);
int		path(char *new);
int		make_total(char **str, char *path);
int		print_error(char **str, char *flag);
int		print_file(char **str, int j, char *flag);
int		count_dir(char **str, char *flag);
int		lenght_year(char *year);
int		print_lien(char **str, char *flag);

char	*check(char *str, char *flag);
char	*make_path(char *str);
char	**ls_a(char *path);
char	**ls(char *path);
char	*concate(char *path, char *str);
char	*print_time(struct stat l, int j);
char	**ls_l(char **str, char *path);
char	**my_lyst(char **str, int count, char *path);
char	*concat_with_space(char *str, char *p);
char	***alloc_list(int count);
char	*print_user(struct stat	l);
char	*print_grop(struct stat	l);
char	*print_per(mode_t st_mode);
char	**makels(int j, char ***my_list);
char	**ls_r(char **str);
char	*concate(char *path, char *str);
void	create_str(char ***my_list, int j, int size, char *str);
char	*create_space(char *str, int *b, int max);
char	**take_name(char **real);
char	*print_size(struct stat l, char type, int max);
char	**alloc_dir(char **str, int i, char *flag);

#endif
