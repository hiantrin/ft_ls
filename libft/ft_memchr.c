/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:58:09 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/14 16:12:12 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	m;

	m = (unsigned char)c;
	dst = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (dst[i] == m)
			return (dst + i);
		i++;
	}
	return (NULL);
}
