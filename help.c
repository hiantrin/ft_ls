/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:15:10 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/23 18:59:53 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		n_str_a(char *path)
{
	int				i;
	DIR				*dir;
	struct dirent	*dirent;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
	{
		perror("Error: ");
		exit(1);
	}
	while ((dirent = readdir(dir)))
		i++;
	closedir(dir);
	return (i);
}

int		n_str(char *path)
{
	int				i;
	DIR				*dir;
	struct dirent	*dirent;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
	{
		perror("Error: ");
		exit(1);
	}
	while ((dirent = readdir(dir)))
	{
		if (dirent->d_name[0] != '.')
			i++;
	}
	closedir(dir);
	return (i);
}

void	remplir_a(char **str, char *path)
{
	int				i;
	struct dirent	*dirent;
	DIR				*dir;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
	{
		write(1, "Error! Unable to open directory.", 32);
		exit(1);
	}
	while ((dirent = readdir(dir)))
	{
		str[i] = ft_strdup(dirent->d_name);
		i++;
	}
	closedir(dir);
}

void	remplir(char **str, char *path)
{
	int				i;
	struct dirent	*dirent;
	DIR				*dir;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
	{
		write(1, "Error! Unable to open directory.", 32);
		exit(1);
	}
	while ((dirent = readdir(dir)))
	{
		if (dirent->d_name[0] != '.')
		{
			str[i] = ft_strdup(dirent->d_name);
			i++;
		}
	}
	closedir(dir);
}

void	help_lien(char *str, char *mine, char *flag)
{
	char	buff[BUFF_SIZE];
	char	*new;
	int		size;
	char	*link;
	int		i;

	size = readlink(str, buff, BUFF_SIZE);
	link = (char *)malloc(sizeof(char) * size + 1);
	link[size] = '\0';
	i = 0;
	while (i < size)
	{
		link[i] = buff[i];
		i++;
	}
	new = check(link, flag);
	if (new != NULL && (new[0] == 'd' || new[0] == 'x' || new[0] == 'r'))
		mine[0] = new[0];
	free(new);
	free(link);
}
