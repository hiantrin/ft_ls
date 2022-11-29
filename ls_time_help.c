/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_time_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 23:24:02 by hiantrin          #+#    #+#             */
/*   Updated: 2019/10/14 23:50:41 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		year(char *year)
{
	int i;
	int j;

	i = 20;
	while (year[i] == ' ')
		i++;
	j = i;
	while (year[j] >= 48 && year[j] <= 57)
		j++;
	year[j] = '\0';
	return (ft_atoi(&year[i]));
}

int		cloc(char *str)
{
	int		i;
	char	*cloc;

	i = 11;
	cloc = (char *)malloc(sizeof(char) * 7);
	cloc[6] = '\0';
	cloc[0] = str[i++];
	cloc[1] = str[i++];
	i++;
	cloc[2] = str[i++];
	cloc[3] = str[i++];
	i++;
	cloc[4] = str[i++];
	cloc[5] = str[i];
	i = ft_atoi(cloc);
	free(cloc);
	return (i);
}

int		day(char *str)
{
	char	*d;
	int		i;
	int		j;
	int		b;

	i = 7;
	while (str[i] == ' ')
		i++;
	j = i;
	while (str[j] != ' ')
		j++;
	d = (char *)malloc(sizeof(char) * ((j - i) + 1));
	d[j - i] = '\0';
	b = 0;
	while (i < j)
		d[b++] = str[i++];
	i = ft_atoi(d);
	free(d);
	return (i);
}

int		month(char *str)
{
	char	*month;
	int		i;

	month = (char *)malloc(sizeof(char) * 4);
	month[3] = '\0';
	month[0] = str[4];
	month[1] = str[5];
	month[2] = str[6];
	i = month_to_num(month);
	free(month);
	return (i);
}

int		month_to_num(char *str)
{
	if (ft_strcmp(str, "Jan") == 0)
		return (1);
	if (ft_strcmp(str, "Feb") == 0)
		return (2);
	if (ft_strcmp(str, "Mar") == 0)
		return (3);
	if (ft_strcmp(str, "Apr") == 0)
		return (4);
	if (ft_strcmp(str, "May") == 0)
		return (5);
	if (ft_strcmp(str, "Jun") == 0)
		return (6);
	if (ft_strcmp(str, "Jul") == 0)
		return (7);
	if (ft_strcmp(str, "Aug") == 0)
		return (8);
	if (ft_strcmp(str, "Sep") == 0)
		return (9);
	if (ft_strcmp(str, "Oct") == 0)
		return (10);
	if (ft_strcmp(str, "Nov") == 0)
		return (11);
	if (ft_strcmp(str, "Dec") == 0)
		return (12);
	return (0);
}
