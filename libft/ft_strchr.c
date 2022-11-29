/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:24:00 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/14 16:34:51 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*m;

	i = 0;
	m = (char *)s;
	if (c == '\0')
	{
		while (m[i] != '\0')
			i++;
		return (m + i);
	}
	while (m[i] != '\0')
	{
		if (m[i] == c)
		{
			return (m + i);
		}
		i++;
	}
	return (NULL);
}
