/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_splice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <rmicolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:37:56 by rmicolon          #+#    #+#             */
/*   Updated: 2018/10/15 20:01:17 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static inline void	ft__list_splice(const t_list_head *list,
									t_list_head *prev,
									t_list_head *next)
{
	t_list_head *first;
	t_list_head *last;

	first = list->next;
	last = list->prev;
	first->prev = prev;
	prev->next = first;
	last->next = next;
	next->prev = last;
}

/*
** ft_list_splice - join two lists, this is designed for stacks
*/

inline void			ft_list_splice(const t_list_head *list, t_list_head *head)
{
	if (!ft_list_empty(list))
		ft__list_splice(list, head, head->next);
}

/*
** ft_list_splice_tail - join two lists, each one being a queue
*/

inline void			ft_list_splice_tail(t_list_head *list, t_list_head *head)
{
	if (!ft_list_empty(list))
		ft__list_splice(list, head->prev, head);
}

/*
** ft_list_splice_init - join two lists and reinitialise the emptied list
*/

inline void			ft_list_splice_init(t_list_head *list, t_list_head *head)
{
	if (!ft_list_empty(list))
	{
		ft__list_splice(list, head, head->next);
		ft_init_list_head(list);
	}
}

/*
** ft_list_splice_tail_init - join two lists and reinitialise the emptied list
*/

inline void			ft_list_splice_tail_init(t_list_head *list,
											t_list_head *head)
{
	if (!ft_list_empty(list))
	{
		ft__list_splice(list, head->prev, head);
		ft_init_list_head(list);
	}
}
