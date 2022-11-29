/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 23:23:44 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/12 21:51:11 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_time(char **str, char *path)
{
	struct stat	l;
	int			i;
	char		**tim;
	char		*p;

	i = 0;
	while (str[i])
		i++;
	tim = (char **)malloc(sizeof(char *) * (i + 1));
	tim[i] = NULL;
	i = 0;
	while (str[i])
	{
		if (path != NULL)
			p = concate(path, str[i]);
		else
			p = str[i];
		lstat(p, &l);
		tim[i] = ft_strdup(ctime(&l.st_mtime));
		if (path != NULL)
			free(p);
		i++;
	}
	true_time(str, tim);
	free_2d(tim);
}

void	true_time(char **str, char **tim)
{
	int		i;
	int		j;
	char	*own;

	i = -1;
	while (str[++i])
	{
		j = i + 1;
		while (str[j])
		{
			if (my_time(tim[i], tim[j]) < 0 ||
			(my_time(tim[i], tim[j]) == 0 && ft_strcmp(str[i], str[j]) > 0))
			{
				own = str[i];
				str[i] = str[j];
				str[j] = own;
				own = ft_strdup(tim[i]);
				free(tim[i]);
				tim[i] = ft_strdup(tim[j]);
				free(tim[j]);
				tim[j] = own;
			}
			j++;
		}
	}
}

char	*print_time(struct stat l, int j)
{
	char	*mine;
	int		i;
	char	*tim;

	mine = ctime(&l.st_mtime);
	tim = (char *)malloc(sizeof(char) * 13);
	tim[12] = '\0';
	i = 4;
	while (i < 16)
	{
		if (i == 11 && (compare_year(l) != 0))
		{
			i = 20;
			if (lenght_year(&mine[20]) < 5)
				tim[j++] = ' ';
			while (mine[i] == ' ')
				i++;
			while (j < 12)
				tim[j++] = mine[i++];
			break ;
		}
		tim[j++] = mine[i++];
	}
	return (tim);
}

int		lenght_year(char *year)
{
	int i;
	int j;

	i = 0;
	while (year[i] == ' ')
		i++;
	j = i;
	while (year[j] >= 48 && year[j] <= 57)
		j++;
	return (j - i);
}

int		compare_year(struct stat l)
{
	time_t	sec;

	sec = time(NULL);
	if ((sec - 15778800) > l.st_mtime || sec < l.st_mtime)
		return (1);
	return (0);
}
