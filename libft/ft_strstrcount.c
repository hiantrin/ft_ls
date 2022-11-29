/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:10:04 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/22 14:31:30 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstrcount(const char *str, const char *to_find)
{
	int	i;
	int	a;
	int	b;
	int	count;

	count = 0;
	i = 0;
	b = 0;
	if (to_find[0] == '\0')
		return (1);
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
			count++;
		b++;
	}
	return (count);
}
