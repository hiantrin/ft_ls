/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:43:32 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/23 18:57:40 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*check(char *str, char *flag)
{
	struct stat	l;
	char		*mine;

	mine = ft_strnew(1);
	if (str[0] == '~')
		str = make_path(str);
	if (lstat(str, &l) == 0)
	{
		print_type(l.st_mode, mine);
		if (mine[0] == 'l' && !(ft_strchr(flag, 'l')) &&
			!(ft_strchr(flag, 'R')))
		{
			help_lien(str, mine, flag);
			return (mine);
		}
		if (!(l.st_mode & S_IXUSR) && mine[0] == 'd')
			mine[0] = 'x';
		if (!(l.st_mode & S_IRUSR) && (mine[0] == 'd' || mine[0] == 'x'))
			mine[0] = 'r';
		return (mine);
	}
	free(mine);
	mine = NULL;
	return (mine);
}

char	*make_path(char *str)
{
	char	*new;
	int		i;
	int		j;

	j = 1;
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 16));
	new[ft_strlen(str) + 16] = '\0';
	i = path(new);
	while (str[j])
		new[i++] = str[j++];
	return (new);
}

int		path(char *new)
{
	int i;

	i = 0;
	new[i++] = '/';
	new[i++] = 'U';
	new[i++] = 's';
	new[i++] = 'e';
	new[i++] = 'r';
	new[i++] = 's';
	new[i++] = '/';
	new[i++] = 'h';
	new[i++] = 'i';
	new[i++] = 'a';
	new[i++] = 'n';
	new[i++] = 't';
	new[i++] = 'r';
	new[i++] = 'i';
	new[i++] = 'n';
	return (i);
}
