/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:38:41 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/13 19:35:16 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	a;
	char	*str;

	a = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[a] != '\0')
		a++;
	a--;
	while ((s[a] == ' ' || s[a] == '\n' || s[a] == '\t') && a > i)
		a--;
	a++;
	str = ft_strsub(s, i, (a - i));
	return (str);
}
