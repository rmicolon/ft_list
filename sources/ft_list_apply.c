/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <rmicolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:45:53 by rmicolon          #+#    #+#             */
/*   Updated: 2018/11/23 15:07:40 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

inline int	ft_list_apply(
						void *priv,
						t_list_head *head,
						unsigned long offset,
						int (*func)(void *, void *, int))
{
	t_list_head		*pos;
	int				step;

	pos = head->next;
	step = 0;
	while (pos != head)
	{
		if (func(priv, (void*)((char*)(pos) - offset), step))
			return (1);
		pos = pos->next;
		++step;
	}
	return (0);
}

inline int	ft_list_apply_rev(
						void *priv,
						t_list_head *head,
						unsigned long offset,
						int (*func)(void *, void *, int))
{
	t_list_head		*pos;
	int				step;

	pos = head;
	step = 0;
	while (pos != head)
	{
		if (func(priv, (void*)((char*)(pos) - offset), step))
			return (1);
		pos = pos->prev;
		++step;
	}
	return (0);
}
