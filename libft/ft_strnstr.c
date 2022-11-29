/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:09:23 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/16 18:29:55 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *to_find, size_t len)
{
	size_t	i;
	size_t	a;
	size_t	b;
	char	*str;

	i = 0;
	a = 0;
	b = 0;
	str = (char *)haystack;
	if (to_find[a] == '\0')
		return (str);
	while (str[b] != '\0' && b < len)
	{
		a = 0;
		i = b;
		while (to_find[a] != '\0' && i < len && str[i] == to_find[a])
		{
			a++;
			i++;
		}
		if (to_find[a] == '\0')
			return (str + b);
		b++;
	}
	return (NULL);
}
