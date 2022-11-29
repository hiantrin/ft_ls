/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 07:23:44 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/05 22:01:58 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ls_l(char **str, char *path)
{
	int		i;
	int		total;
	char	**mine;

	i = 0;
	total = 0;
	while (str[i])
		i++;
	mine = my_lyst(str, i, path);
	total = make_total(str, path);
	if (path != NULL && i != 0)
	{
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
	free_2d(str);
	return (mine);
}

int		make_total(char **str, char *path)
{
	struct stat	l;
	char		*p;
	int			i;
	int			total;

	i = 0;
	total = 0;
	while (str[i])
	{
		if (path != NULL)
			p = concate(path, str[i]);
		else
			p = str[i];
		lstat(p, &l);
		total = total + l.st_blocks;
		i++;
		if (path != NULL)
			free(p);
	}
	return (total);
}
