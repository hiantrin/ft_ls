/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:35:26 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/14 14:08:17 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**my_lyst(char **str, int count, char *path)
{
	char		***my_list;
	int			i;
	char		*p;
	int			max;
	struct stat	l;

	i = 0;
	my_list = alloc_list(count);
	max = major_num(str, path);
	while (i < count)
	{
		if (path != NULL)
			p = concate(path, str[i]);
		else
			p = str[i];
		lstat(p, &l);
		my_list[i] = make_my_lyst(p, str[i], max, l);
		i++;
		if (path != NULL)
			free(p);
	}
	return (makels(count, my_list));
}

char	**make_my_lyst(char *p, char *str, int max, struct stat l)
{
	char	**my_list;
	int		j;

	j = 0;
	my_list = (char **)malloc(sizeof(char *) * 8);
	my_list[7] = NULL;
	my_list[0] = print_per(l.st_mode);
	my_list[1] = ft_itoa(l.st_nlink);
	my_list[2] = print_user(l);
	my_list[3] = print_grop(l);
	my_list[4] = print_size(l, my_list[0][0], max);
	my_list[5] = print_time(l, j);
	if (my_list[0][0] != 'l')
		my_list[6] = ft_strdup(str);
	else
		my_list[6] = concat_with_space(str, p);
	return (my_list);
}

int		major_num(char **str, char *path)
{
	char		*p;
	struct stat	l;
	int			i;
	int			max;
	char		*min;

	max = 0;
	i = 0;
	while (str[i])
	{
		if (path != NULL)
			p = concate(path, str[i]);
		else
			p = str[i];
		lstat(p, &l);
		min = ft_itoa(minor(l.st_rdev));
		if ((int)ft_strlen(min) > max)
			max = ft_strlen(min);
		if (path != NULL)
			free(p);
		free(min);
		i++;
	}
	return (max);
}

char	*print_size(struct stat l, char type, int max)
{
	char	*maj;
	char	*min;
	char	*str;

	if (type != 'c' && type != 'b')
		return (ft_itoa(l.st_size));
	else
	{
		maj = ft_itoa(major(l.st_rdev));
		min = ft_itoa(minor(l.st_rdev));
		str = (char *)malloc(sizeof(char) * (ft_strlen(maj) + max + 3));
		str[ft_strlen(maj) + max + 2] = '\0';
		print_major_minor(maj, min, max, str);
	}
	return (str);
}

void	print_major_minor(char *maj, char *min, int max, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (maj[j])
		str[i++] = maj[j++];
	str[i++] = ',';
	str[i++] = ' ';
	j = 0;
	while (j < (max - (int)ft_strlen(min)))
	{
		str[i++] = ' ';
		j++;
	}
	j = 0;
	while (min[j])
		str[i++] = min[j++];
	free(min);
	free(maj);
}
