/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <rmicolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:37:25 by rmicolon          #+#    #+#             */
/*   Updated: 2018/10/20 16:42:11 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** ft_list_is_last - test wether @list is the last entry in @head
*/

inline int	ft_list_is_last(const t_list_head *list, const t_list_head *head)
{
	return (list->next == head);
}

/*
** ft_list_empty - test wether a list is empty
*/

inline int	ft_list_empty(const t_list_head *head)
{
	return (head->next == head);
}

/*
** ft_list_empty_careful - test wether a list is empty and not being modified
*/

inline int	ft_list_empty_careful(const t_list_head *head)
{
	t_list_head *next;

	next = head->next;
	return ((next == head) && (next == head->prev));
}

/*
** ft_list_is_singular - test wether a list has just one entry
*/

inline int	ft_list_is_singular(const t_list_head *head)
{
	return (!ft_list_empty(head) && (head->next == head->prev));
}
