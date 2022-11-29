/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 23:34:50 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/27 22:12:03 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "string.h"

int		main(int argc, char **argv)
{
	char	*flag;
	char	*c;
	int		i;

	argc = 0;
	flag = ft_strnew(6);
	c = ft_strnew(1);
	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if ((argv[i][1] == '-') && argv[i][2] == '\0')
		{
			i++;
			break ;
		}
		if (argv[i][1] == '\0')
			break ;
		create_flag(flag, argv[i], c);
		i++;
	}
	concate_flag(flag, c, &argv[i]);
	transfer_to_myls(flag, &argv[i], c);
	free(flag);
	free(c);
	return (0);
}

void	create_flag(char *flag, char *str, char *c)
{
	int	i;
	int f;

	i = 0;
	f = 0;
	while (flag[f])
		f++;
	while (str[++i])
	{
		if ((ft_strchr("latRr1", str[i]))
			&& ft_strchr(flag, str[i]) == NULL)
		{
			if (str[i] == 'R')
				c[0] = str[i];
			else
				flag[f++] = str[i];
		}
		else if (ft_strchr("latRr1", str[i]) == NULL)
		{
			write(2, "ls: illegal option -- ", 22);
			ft_putchar(str[i]);
			write(2, "\nusage: ls [-Ralrt1] [file ...]\n", 32);
			exit(1);
		}
	}
}

void	transfer_to_myls(char *flag, char **str, char *c)
{
	int		i;
	int		j;
	char	*nul;
	char	**mine;
	int		a;

	nul = NULL;
	if (str[0] == NULL)
		print_my_ls(flag, &nul, ".");
	else
	{
		str = take_name(str);
		true_place(str);
		a = print_lien(str, flag);
		j = print_error(str, flag);
		if ((i = count_dir(str, flag)) != 0)
		{
			mine = alloc_dir(str, i, flag);
			if (j != 0)
				ft_putchar('\n');
			print_dir(mine, i + j + a, c, flag);
			free_2d(mine);
		}
		free_2d(str);
	}
}

void	print_my_ls(char *flag, char **str, char *path)
{
	char	**real;
	char	**name;

	if (path == NULL)
		real = str;
	else
	{
		if (ft_strchr(flag, 'a') != NULL)
			real = ls_a(path);
		else
			real = ls(path);
	}
	if (ft_strchr(flag, 't') != NULL)
		ls_time(real, path);
	if (ft_strchr(flag, 'r') != NULL)
		real = ls_r(real);
	name = take_name(real);
	if (ft_strchr(flag, 'l') != NULL)
		real = ls_l(real, path);
	if (ft_strchr(flag, 'R') != NULL)
		ls_rr(real, path, flag, name);
	help_for_print(real, name, flag);
}

void	help_for_print(char **real, char **name, char *flag)
{
	int i;

	i = 0;
	if (ft_strchr(flag, 'R') == NULL)
	{
		while (real[i])
			ft_putendl(real[i++]);
	}
	free_2d(real);
	free_2d(name);
}
