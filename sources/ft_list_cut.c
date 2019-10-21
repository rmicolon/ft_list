/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_cut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <rmicolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:22:47 by rmicolon          #+#    #+#             */
/*   Updated: 2018/10/20 16:32:37 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static inline void	ft__list_cut_position(t_list_head *list,
										t_list_head *head,
										t_list_head *entry)
{
	t_list_head *new_first;

	new_first = entry->next;
	list->next = head->next;
	list->next->prev = list;
	list->prev = entry;
	entry->next = list;
	head->next = new_first;
	new_first->prev = head;
}

/*
** ft_list_cut_position - cut from @head to @entry (included) and store it in
** @list
*/

inline void			ft_list_cut_position(t_list_head *list,
										t_list_head *head,
										t_list_head *entry)
{
	if (ft_list_empty(head))
		return ;
	if (ft_list_is_singular(head) &&
			(head->next != entry && head != entry))
		return ;
	if (entry == head)
		ft_init_list_head(list);
	else
		ft__list_cut_position(list, head, entry);
}

/*
** ft_list_cut_before - cut from @head to @entry (excluded) and store it in
** @list
*/

inline void			ft_list_cut_before(t_list_head *list,
									t_list_head *head,
									t_list_head *entry)
{
	if (head->next == entry)
	{
		ft_init_list_head(list);
		return ;
	}
	list->next = head->next;
	list->next->prev = list;
	list->prev = entry->prev;
	list->prev->next = list;
	head->next = entry;
	entry->prev = head;
}
