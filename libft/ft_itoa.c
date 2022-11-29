/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:36:44 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/20 14:41:04 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		lenght(long j)
{
	int	a;

	a = 0;
	if (j == 0)
		a++;
	if (j < 0)
	{
		j = j * -1;
		a++;
	}
	while (j > 0)
	{
		j = j / 10;
		a++;
	}
	return (a);
}

char			*ft_itoa(int i)
{
	char	*str;
	int		a;
	long	s;

	s = i;
	a = lenght(s);
	if (!(str = (char *)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	if (s == 0)
	{
		str[0] = 48;
		return (str);
	}
	str[a--] = '\0';
	if (s < 0)
	{
		str[0] = '-';
		s = s * -1;
	}
	while (s > 0)
	{
		str[a--] = ((s % 10) + 48);
		s = s / 10;
	}
	return (str);
}
