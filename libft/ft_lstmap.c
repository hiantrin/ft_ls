/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:17:19 by hiantrin          #+#    #+#             */
/*   Updated: 2019/04/20 15:30:50 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *save;
	t_list *a;

	if (lst == NULL || f == NULL)
		return (NULL);
	save = f(lst);
	a = save;
	lst = lst->next;
	while (lst != NULL)
	{
		if (a == NULL)
			return (NULL);
		a->next = f(lst);
		a = a->next;
		lst = lst->next;
	}
	return (save);
}
