/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:47:46 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/14 16:43:01 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*m;

	i = 0;
	m = (char *)s;
	while (m[i] != '\0')
		i++;
	if (c == '\0')
		return (m + i);
	i--;
	while (i >= 0)
	{
		if (m[i] == c)
		{
			return (m + i);
		}
		i--;
	}
	return (NULL);
}
