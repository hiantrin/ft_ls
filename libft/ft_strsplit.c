/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:16:59 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/16 18:36:44 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		len(char const *s, char c)
{
	int start;
	int end;
	int i;

	i = 0;
	end = 0;
	start = 0;
	while (s[start] != '\0')
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		if (s[start] == '\0')
			break ;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		start = end;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		start;
	int		end;
	char	**str;
	int		i;

	i = 0;
	start = 0;
	end = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (len(s, c) + 1))))
		return (NULL);
	while (i < len(s, c))
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		str[i] = ft_strsub(s, start, (end - start));
		start = end;
		i++;
	}
	str[i] = NULL;
	return (str);
}
