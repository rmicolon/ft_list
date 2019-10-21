/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <rmicolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:27:38 by rmicolon          #+#    #+#             */
/*   Updated: 2018/10/15 20:03:39 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
** ft_init_list_head - Initialize a list head
*/

inline void		ft_init_list_head(t_list_head *list_head)
{
	list_head->next = list_head;
	list_head->prev = list_head;
}
