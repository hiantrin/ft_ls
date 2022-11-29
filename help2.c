/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:44:36 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/23 14:35:54 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**take_name(char **real)
{
	char	**name;
	int		i;

	i = 0;
	while (real[i])
		i++;
	name = (char **)malloc(sizeof(char *) * (i + 1));
	name[i] = NULL;
	i = 0;
	while (real[i])
	{
		name[i] = ft_strdup(real[i]);
		i++;
	}
	return (name);
}

char	*concate(char *path, char *str)
{
	int		a;
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	a = ft_strlen(path) + ft_strlen(str);
	new = (char *)malloc(sizeof(char) * a + 2);
	new[a + 1] = '\0';
	while (j < (a = ft_strlen(path)))
		new[i++] = path[j++];
	j = 0;
	if (new[i - 1] != '/')
	{
		new[i++] = '/';
		a = ft_strlen(str);
	}
	else
		a = ft_strlen(str) + 1;
	while (j < a)
		new[i++] = str[j++];
	return (new);
}

void	free_2d(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_3d(char ***str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free_2d(str[i]);
		i++;
	}
	free(str);
}

void	help_dir(char *mine, char *flag, char *new, char *c)
{
	DIR		*dir;
	char	*nul;
	int		i;
	char	*newflag;

	i = 0;
	nul = NULL;
	if (new[0] == 'r')
	{
		write(2, "ls: ", 4);
		ft_putstr(mine);
		write(2, ": Permission denied\n", 20);
	}
	if (new[0] == 'd')
	{
		if ((dir = opendir(mine)))
		{
			newflag = ft_strjoin(flag, c);
			print_my_ls(newflag, &nul, mine);
			free(newflag);
			closedir(dir);
		}
		else
			perror(mine);
	}
}
