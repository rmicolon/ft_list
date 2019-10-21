/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <rmicolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:04:22 by rmicolon          #+#    #+#             */
/*   Updated: 2018/10/22 14:09:07 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** ft__list_del_entry - Delete entry from list by making the prev/next
** point to each other
*/

static inline void	ft__list_del_entry(t_list_head *entry)
{
	entry->prev->next = entry->next;
	entry->next->prev = entry->prev;
}

/*
** ft_list_move - delete entry from one list and add as another's head
*/

inline void			ft_list_move(t_list_head *list, t_list_head *head)
{
	ft__list_del_entry(list);
	ft_list_add(list, head);
}

/*
** ft_list_move_tail - delete entry from one list and add as another's tail
*/

inline void			ft_list_move_tail(t_list_head *list, t_list_head *head)
{
	ft__list_del_entry(list);
	ft_list_add_tail(list, head);
}

/*
** ft_list_rotate_left - rotate the list to the left
*/

inline void			ft_list_rotate_left(t_list_head *head)
{
	t_list_head	*first;

	if (!ft_list_empty(head))
	{
		first = head->next;
		ft_list_move_tail(first, head);
	}
}

inline void			ft_list_rotate_right(t_list_head *head)
{
	t_list_head	*last;

	if (!ft_list_empty(head))
	{
		last = head->prev;
		ft_list_move(last, head);
	}
}
