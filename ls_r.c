/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:01:55 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/23 15:07:01 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_rr(char **str, char *path, char *flag, char **name)
{
	int		i;
	char	*p;
	char	*new;

	i = 0;
	while (str[i])
		ft_putendl(str[i++]);
	i = 0;
	while (str[i])
	{
		if (path != NULL)
			p = concate(path, name[i]);
		else
			p = name[i];
		new = check(p, flag);
		if ((new == NULL || new[0] == 'd' || new[0] == 'x' || new[0] == 'r') &&
			ft_strcmp(name[i], "..") != 0 && ft_strcmp(name[i], ".") != 0)
			ls_rr_help(new, name[i], flag, p);
		if (path != NULL)
			free(p);
		if (new != NULL)
			free(new);
		i++;
	}
}

void	ls_rr_help(char *new, char *name, char *flag, char *p)
{
	char	*nul;
	DIR		*dir;

	ft_putchar('\n');
	ft_putstr(p);
	ft_putstr(":\n");
	nul = NULL;
	if ((dir = opendir(p)))
	{
		if (new == NULL)
			perror(name);
		else if (new != NULL && new[0] == 'r')
		{
			ft_putstr("ls: ");
			ft_putstr(name);
			ft_putendl(": Permission denied");
		}
		else if (new[0] == 'd')
		{
			print_my_ls(flag, &nul, p);
		}
		closedir(dir);
	}
	else
		perror(name);
}

char	**ls_r(char **str)
{
	char	**rever;
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	rever = (char **)malloc(sizeof(char *) * (i + 1));
	rever[i] = NULL;
	i--;
	j = 0;
	while (i >= 0)
	{
		rever[j++] = ft_strdup(str[i]);
		free(str[i]);
		i--;
	}
	free(str);
	return (rever);
}

void	print_dir(char **mine, int a, char *c, char *flag)
{
	char	*new;
	int		i;

	i = 0;
	while (mine[i])
	{
		if (a > 1)
		{
			ft_putstr(mine[i]);
			ft_putendl(":");
		}
		new = check(mine[i], flag);
		if (new[0] == 'd' || new[0] == 'r')
			help_dir(mine[i], flag, new, c);
		if (mine[i + 1] != NULL)
			ft_putchar('\n');
		if (new != NULL)
			free(new);
		i++;
	}
}

int		my_time(char *str, char *mine)
{
	int	i;

	if ((i = year(str) - year(mine)) != 0)
		return (year(str) - year(mine));
	if ((i = month(str) - month(mine)) != 0)
		return (month(str) - month(mine));
	if ((i = day(str) - day(mine)) != 0)
		return (day(str) - day(mine));
	return (cloc(str) - cloc(mine));
}
