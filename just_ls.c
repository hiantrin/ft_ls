/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 05:25:59 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/08 16:01:04 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ls_a(char *path)
{
	char	**str;
	int		i;

	i = n_str_a(path);
	str = (char **)malloc(sizeof(char *) * (i + 1));
	str[i] = NULL;
	remplir_a(str, path);
	true_place(str);
	return (str);
}

char	**ls(char *path)
{
	char	**str;
	int		i;

	i = n_str(path);
	str = (char **)malloc(sizeof(char *) * (i + 1));
	str[i] = NULL;
	remplir(str, path);
	true_place(str);
	return (str);
}

void	true_place(char **str)
{
	char	*own;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) < 0)
			{
				own = ft_strdup(str[i]);
				free(str[i]);
				str[i] = ft_strdup(str[j]);
				free(str[j]);
				str[j] = own;
			}
			j++;
		}
		i++;
	}
}
