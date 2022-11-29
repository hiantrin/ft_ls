/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:52:03 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/05 16:10:36 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*print_per(mode_t st_mode)
{
	char	*perm;

	perm = (char *)malloc(sizeof(char) * 11);
	perm[10] = '\0';
	print_type(st_mode, perm);
	print_usr(st_mode, &perm);
	print_grp(st_mode, &perm);
	print_oth(st_mode, &perm);
	return (perm);
}

void	print_type(mode_t st_mode, char *perm)
{
	if ((st_mode & S_IFMT) == S_IFDIR)
		perm[0] = 'd';
	else if ((st_mode & S_IFMT) == S_IFREG)
		perm[0] = '-';
	else if ((st_mode & S_IFMT) == S_IFLNK)
		perm[0] = 'l';
	else if ((st_mode & S_IFMT) == S_IFIFO)
		perm[0] = 'p';
	else if ((st_mode & S_IFMT) == S_IFCHR)
		perm[0] = 'c';
	else if ((st_mode & S_IFMT) == S_IFBLK)
		perm[0] = 'b';
	else if ((st_mode & S_IFMT) == S_IFSOCK)
		perm[0] = 's';
}

void	print_usr(mode_t st_mode, char **perm)
{
	if (st_mode & S_IRUSR)
		perm[0][1] = 'r';
	else
		perm[0][1] = '-';
	if (st_mode & S_IWUSR)
		perm[0][2] = 'w';
	else
		perm[0][2] = '-';
	if (st_mode & S_IXUSR)
		perm[0][3] = 'x';
	else
		perm[0][3] = '-';
	if ((st_mode & S_ISUID) && perm[0][3] == 'x')
		perm[0][3] = 's';
	else if ((st_mode & S_ISUID) && perm[0][3] == '-')
		perm[0][3] = 'S';
}

void	print_grp(mode_t st_mode, char **perm)
{
	if (st_mode & S_IRGRP)
		perm[0][4] = 'r';
	else
		perm[0][4] = '-';
	if (st_mode & S_IWGRP)
		perm[0][5] = 'w';
	else
		perm[0][5] = '-';
	if (st_mode & S_IXGRP)
		perm[0][6] = 'x';
	else
		perm[0][6] = '-';
	if ((st_mode & S_ISGID) && perm[0][6] == 'x')
		perm[0][6] = 's';
	else if ((st_mode & S_ISGID) && perm[0][6] == '-')
		perm[0][6] = 'S';
}

void	print_oth(mode_t st_mode, char **perm)
{
	if (st_mode & S_IROTH)
		perm[0][7] = 'r';
	else
		perm[0][7] = '-';
	if (st_mode & S_IWOTH)
		perm[0][8] = 'w';
	else
		perm[0][8] = '-';
	if (st_mode & S_IXOTH)
		perm[0][9] = 'x';
	else
		perm[0][9] = '-';
	if ((st_mode & S_ISVTX) && perm[0][9] == 'x')
		perm[0][9] = 't';
	else if ((st_mode & S_ISVTX) && perm[0][9] == '-')
		perm[0][9] = 'T';
}
