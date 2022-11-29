/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:02:49 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/12 20:09:22 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	***alloc_list(int count)
{
	char ***my_list;

	my_list = (char ***)malloc(sizeof(char **) * (count + 1));
	my_list[count] = NULL;
	return (my_list);
}

char	*print_user(struct stat	l)
{
	struct passwd	*pwd;
	char			*user;

	pwd = getpwuid(l.st_uid);
	user = ft_strdup(pwd->pw_name);
	return (user);
}

char	*print_grop(struct stat	l)
{
	struct group	*grp;
	char			*grop;

	grp = getgrgid(l.st_gid);
	grop = ft_strdup(grp->gr_name);
	return (grop);
}

char	*concat_with_space(char *str, char *p)
{
	char	*link;
	int		i;
	int		j;
	char	buff[BUFF_SIZE];
	int		size;

	size = readlink(p, buff, BUFF_SIZE);
	i = size + ft_strlen(str) + 4;
	link = (char *)malloc(sizeof(char) * i + 1);
	link[i] = '\0';
	i = 0;
	j = 0;
	while (str[j])
		link[i++] = str[j++];
	link[i++] = ' ';
	link[i++] = '-';
	link[i++] = '>';
	link[i++] = ' ';
	j = 0;
	while (j < size)
		link[i++] = buff[j++];
	return (link);
}
