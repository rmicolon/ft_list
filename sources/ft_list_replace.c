/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <rmicolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 18:20:42 by rmicolon          #+#    #+#             */
/*   Updated: 2018/10/22 15:05:02 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** ft_list_replace - replace old entry by new one
*/

inline void	ft_list_replace(t_list_head *old, t_list_head *new)
{
	new->next = old->next;
	new->next->prev = new;
	new->prev = old->prev;
	new->prev->next = new;
}

/*
** ft_list_replace_init - replace old entry by new one and reinitialize it
*/

inline void	ft_list_replace_init(t_list_head *old, t_list_head *new)
{
	ft_list_replace(old, new);
	ft_init_list_head(old);
}

/*
** ft_list_swap - swap two elements of one or two lists
*/

inline void	ft_list_swap(t_list_head *first, t_list_head *second)
{
	t_list_head	tmp;

	tmp.next = first->next;
	tmp.prev = first->prev;
	first->next = second->next;
	first->next->prev = first;
	first->prev = second->prev;
	first->prev->next = first;
	second->next = tmp.next;
	second->next->prev = second;
	second->prev = tmp.prev;
	second->prev->next = second;
}
