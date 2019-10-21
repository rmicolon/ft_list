/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <rmicolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:12:27 by rmicolon          #+#    #+#             */
/*   Updated: 2018/10/15 20:03:56 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** ft__list_del - Delete a list entry by making the prev/next
** point to each other
*/

inline void	ft__list_del(t_list_head *next, t_list_head *prev)
{
	prev->next = next;
	next->prev = prev;
}

/*
** ft__list_del_entry - Delete entry from list
*/

inline void	ft__list_del_entry(t_list_head *entry)
{
	ft__list_del(entry->next, entry->prev);
}

/*
** ft_list_del - Delete entry from list
*/

inline void			ft_list_del(t_list_head *entry)
{
	ft__list_del_entry(entry);
	entry->next = LIST_POISON1;
	entry->prev = LIST_POISON2;
}

/*
** ft_list_del_init - Delete entry from list and reinitialize it
*/

inline void			ft_list_del_init(t_list_head *entry)
{
	ft__list_del_entry(entry);
	ft_init_list_head(entry);
}
