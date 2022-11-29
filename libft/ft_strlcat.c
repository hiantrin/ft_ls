/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:35:55 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/22 14:40:23 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	a;
	size_t	b;
	size_t	j;

	a = ft_strlen(dest);
	b = ft_strlen(src);
	i = 0;
	j = 0;
	if (size <= a)
		return (b + size);
	while (i < (size - 1) && dest[i] != '\0')
		i++;
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (a + b);
}
