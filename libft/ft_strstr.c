/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:15:18 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/22 14:14:10 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *to_find)
{
	int		i;
	int		a;
	int		b;
	char	*str;

	i = 0;
	a = 0;
	b = 0;
	str = (char *)haystack;
	if (to_find[a] == '\0')
		return (str);
	while (str[b] != '\0')
	{
		a = 0;
		i = b;
		while (to_find[a] != '\0' && str[i] == to_find[a])
		{
			i++;
			a++;
		}
		if (to_find[a] == '\0')
			return (str + b);
		b++;
	}
	return (NULL);
}
