/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <rmicolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:10:26 by rmicolon          #+#    #+#             */
/*   Updated: 2018/10/15 20:03:25 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** ft__list_add - Insert a new entry between two known consecutive entries
*/

static inline void	ft__list_add(t_list_head *new,
								t_list_head *prev,
								t_list_head *next)
{
	prev->next = new;
	new->prev = prev;
	new->next = next;
	next->prev = new;
}

/*
** ft_list_add - Insert a new entry after the specified head
*/

inline void			ft_list_add(t_list_head *new, t_list_head *head)
{
	ft__list_add(new, head, head->next);
}

/*
** ft_list_add_tail - Insert a new entry before the specified head
*/

inline void			ft_list_add_tail(t_list_head *new, t_list_head *head)
{
	ft__list_add(new, head->prev, head);
}
