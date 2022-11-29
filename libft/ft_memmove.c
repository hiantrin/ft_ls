/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:13:10 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/20 15:08:21 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*s3;

	s2 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	if ((size_t)(s2 - s1) > len)
		ft_memcpy(s2, s1, len);
	else
	{
		s3 = (unsigned char *)malloc(sizeof(char) * len);
		if (s3 == NULL)
			return (NULL);
		ft_memcpy(s3, s1, len);
		ft_memcpy(s2, s3, len);
	}
	return (s2);
}
