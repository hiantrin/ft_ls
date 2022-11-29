/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:47:06 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/23 14:24:12 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**makels(int j, char ***my_list)
{
	char	**mine;
	int		i;
	int		size;
	int		b;

	i = 1;
	size = 10 + 9 + 12;
	while (i < 5)
	{
		size = size + lenght(my_list, i);
		i++;
	}
	mine = (char **)malloc(sizeof(char *) * (j + 1));
	mine[j] = NULL;
	i = 0;
	while (i < j)
	{
		b = size + ft_strlen(my_list[i][6]);
		mine[i] = (char *)malloc(sizeof(char) * (b + 1));
		mine[i][b] = '\0';
		create_str(my_list, i, size, mine[i]);
		i++;
	}
	free_3d(my_list);
	return (mine);
}

int		lenght(char ***my_list, int j)
{
	int	i;
	int	b;
	int	c;

	i = 0;
	b = 0;
	while (my_list[i])
	{
		if ((c = ft_strlen(my_list[i][j])) > b)
			b = c;
		i++;
	}
	return (b);
}

void	create_str(char ***my_list, int j, int size, char *str)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	b = 0;
	while (my_list[j][i])
	{
		a = 0;
		while (my_list[j][i][a])
			str[b++] = my_list[j][i][a++];
		size = lenght(my_list, i);
		if (i == 0)
			create_space(str, &b, 2 + (lenght(my_list, i + 1) -
			ft_strlen(my_list[j][i + 1])));
		else if (i == 1 || i == 4 || i == 5)
			create_space(str, &b, 1);
		else if (i == 2)
			create_space(str, &b, 2 + (size -
			ft_strlen(my_list[j][i])));
		else if (i == 3)
			create_space(str, &b, (size - ft_strlen(my_list[j][i]))
			+ 2 + (lenght(my_list, i + 1) - ft_strlen(my_list[j][i + 1])));
		i++;
	}
}

char	*create_space(char *str, int *b, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		str[*b] = ' ';
		(*b)++;
		i++;
	}
	return (str);
}

void	concate_flag(char *flag, char *c, char **str)
{
	int i;

	i = 0;
	if (str[0] == NULL)
	{
		while (flag[i])
			i++;
		flag[i] = c[0];
	}
}
