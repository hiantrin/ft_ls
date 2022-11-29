/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_transfer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:02:23 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/15 16:05:21 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		print_lien(char **str, char *flag)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		new = check(str[i], flag);
		if (new == NULL)
			j++;
		if (new != NULL)
			free(new);
	}
	return (j);
}

int		print_error(char **str, char *flag)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		new = check(str[i], flag);
		if (new == NULL)
		{
			write(2, "ls: ", 4);
			perror(str[i]);
		}
		else if (new[0] != 'd' && new[0] != 'x' && new[0] != 'r')
			j++;
		if (new != NULL)
			free(new);
		i++;
	}
	print_file(str, j, flag);
	return (j);
}

int		print_file(char **str, int j, char *flag)
{
	char	**mine;
	char	*new;
	int		i;

	if (j == 0)
		return (0);
	mine = (char **)malloc(sizeof(char *) * (j + 1));
	mine[j] = NULL;
	i = 0;
	j = 0;
	while (str[i])
	{
		new = check(str[i], flag);
		if (new != NULL && new[0] != 'd' && new[0] != 'x' && new[0] != 'r')
		{
			mine[j] = ft_strdup(str[i]);
			j++;
		}
		if (new != NULL)
			free(new);
		i++;
	}
	print_my_ls(flag, mine, NULL);
	return (0);
}

int		count_dir(char **str, char *flag)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		new = check(str[i], flag);
		if (new != NULL && (new[0] == 'd' || new[0] == 'x' || new[0] == 'r'))
			j++;
		if (new != NULL)
			free(new);
		i++;
	}
	return (j);
}

char	**alloc_dir(char **str, int i, char *flag)
{
	char	*new;
	char	**mine;
	int		j;

	mine = (char **)malloc(sizeof(char *) * (i + 1));
	mine[i] = NULL;
	i = 0;
	j = 0;
	while (str[i])
	{
		new = check(str[i], flag);
		if (new != NULL && (new[0] == 'd' || new[0] == 'x' || new[0] == 'r'))
		{
			mine[j] = ft_strdup(str[i]);
			j++;
		}
		if (new != NULL)
			free(new);
		i++;
	}
	if (ft_strchr(flag, 't') != NULL)
		ls_time(mine, NULL);
	if (ft_strchr(flag, 'r') != NULL)
		mine = ls_r(mine);
	return (mine);
}
