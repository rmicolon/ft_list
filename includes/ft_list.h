/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicolon <rmicolon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:20:41 by rmicolon          #+#    #+#             */
/*   Updated: 2018/11/23 15:07:36 by rmicolon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** A simple implementation of linux kernel's linked lists compliant with
** 42 coding style. Most useful functionalities are provided as MACROS
** documented below. Some more functionalities can be accessed by using
** the functions provided in the library, which are briefly explained
** in the corresponding .c files.
*/

#ifndef FT_LIST_H
# define FT_LIST_H

/*
** INTERNAL MACROS
**
** Used mainly for coding style compliance and/or convenience, thus shouldn't
** usually be used outside of this file
*/
# define LIST_POISON1  ((void *) 0x00100100)
# define LIST_POISON2  ((void *) 0x00200200)
# define OFFSETOF(type, member) (unsigned long)(&((type *)0)->member)
# define LCP(list, head, entry) ft_list_cut_position(list, head, entry)
# define LCB(list, head, entry) ft_list_cut_before(list, head, entry)
# define LA(p, t, m, h, f) ft_list_apply(p, h, OFFSETOF(t, m), f)
# define LAR(p, t, m, h, f) ft_list_apply_rev(p, h, OFFSETOF(t, m), f)

/*
** LIST_ENTRY(ptr, type, mb)
** LIST_FIRST_ENTRY(ptr, type, mb)
**
** LIST_LAST_ENTRY(ptr, type, mb)
**
** Used to find the parent struct from the current/first/last element
** of the list
** @ptr:		the &t_list_head pointer
** @type:		type of the parent structure
** @mb:			name of t_list_head within the struct
*/
# define LIST_ENTRY(ptr, type, mb) ((type*)((char*)(ptr) - OFFSETOF(type, mb)))
# define LIST_FIRST_ENTRY(ptr, type, mb) LIST_ENTRY((ptr)->next, type, mb)
# define LIST_LAST_ENTRY(ptr, type, mb) LIST_ENTRY((ptr)->prev, type, mb)

/*
** LIST_NEXT_ENTRY(pos, mb)
** LIST_PREV_ENTRY(pos, mb)
**
** Used to find the next/previous entry in the list
** @pos:		the type * to cursor
** @mb:			nem of t_list_head in the struct
*/
# define LIST_NEXT_ENTRY(pos, mb) LIST_ENTRY((pos)->mb.next, typeof(*(pos)), mb)
# define LIST_PREV_ENTRY(pos, mb) LIST_ENTRY((pos)->mb.prev, typeof(*(pos)), mb)

/*
** LIST_HEAD(name)
**
** Declare a variable t_list_head name to use as the head of the list
** @name:		the name of the head of the list
*/
# define LIST_HEAD(name) t_list_head name = { &(name), &(name) }

/*
** INIT_LIST_HEAD(head)
**
** Init a new list with @head as the new head
** @head:		the &t_list_head pointer to use as head of the new list
*/
# define INIT_LIST_HEAD(head) ft_init_list_head(head)

/*
** LIST_ADD(new, head)
** LIST_ADD_TAIL(new, head)
**
** Add a new element repectively after/before the head element given
** @new:		the new &t_list_head pointer to be added
** @head:		the reference &t_list_head pointer after/before which @new
**				will be added
*/
# define LIST_ADD(new, head) ft_list_add(new, head)
# define LIST_ADD_TAIL(new, head) ft_list_add_tail(new, head)

/*
** LIST_DEL(entry)
**
** Add an element of the list (not responsible for freeing memory)
** @entry:		the &t_list_head pointer of the element to be deleted
**				from the list
*/
# define LIST_DEL(entry) ft_list_del(entry)

/*
** LIST_REPLACE(old, new)
** LIST_REPLACE_INIT(old, new)
**
** Replace an element of the list by a new one. In case of LIST_REPLACE_INIT,
** make the old element a head of a new list
** @old:		the &t_list_head pointer of the element to be replaced
** @new:		the &t_list_head pointer of the element to replace old by
*/
# define LIST_REPLACE(old, new) ft_list_replace(old, new)
# define LIST_REPLACE_INIT(old, new) ft_list_replace_init(old, new)

/*
** LIST_MOVE(list, head)
** LIST_MOVE_TAIL(list, head)
**
** Delete an element from a list and add it after/before another list's head,
** @list:		the &t_list_head pointer element to be removed
** @head:		the &t_list_head pointer of the head of the list the element
**				will be added to
*/
# define LIST_MOVE(list, head) ft_list_move(list, head)
# define LIST_MOVE_TAIL(list, head) ft_list_move_tail(list, head)

/*
** LIST_ROTATE_LEFT(head)
** LIST_ROTATE_RIGHT(head)
**
** Rotate a list's head to the left/right
** @head:		the &t_list_head pointer head of the list
*/
# define LIST_ROTATE_LEFT(head) ft_list_rotate_left(head)
# define LIST_ROTATE_RIGHT(head) ft_list_rotate_right(head)

/*
** LIST_SWAP(first, second)
**
** Swap two elemtents, in out out of a list
** @first:		the first &t_list_head poiter to swap
** @second:		the second &t_list_head poiter to swap
*/
# define LIST_SWAP(first, second) ft_list_swap(first, second)

/*
** LIST_IS_LAST(list, head)
**
** Test wether @list is the last entry in @head
** @list:		the &t_list_head pointer of the element to Test
** @head:		the &t_list_head pointer of the head of the list
*/
# define LIST_IS_LAST(list, head) ft_list_is_last(list, head)

/*
** LIST_IS_EMPTY(head)
** LIST_IS_SINGULAR(head)
**
** Test wether a list is empty/contains only one entry
** @head:		the &t_list_head pointer of the head of the list to test
*/
# define LIST_IS_EMPTY(head) ft_list_empty(head)
# define LIST_IS_SINGULAR(head) ft_list_is_singular(head)

/*
** LIST_CUT_POSITION(list, head, entry)
** LIST_CUT_BEFORE(list, head, entry)
**
** Cut a list into two, from @head to @entry included/excluded
** @list:		a &t_list_head pointer of a new list to add all removed
**				entries
** @head:		the &t_list_head pointer of a list with entries
** @entry:		the &t_list_head pointer of an entry within @head, until
**				which @head will be cut (included/excluded).
**				If @entry = @head, all entries on @head are moved
**				to @list
*/
# define LIST_CUT_POSITION(list, head, entry) LCP(list, head, entry)
# define LIST_CUT_BEFORE(list, head, entry) LCB(list, head, entry)

/*
** LIST_SPLICE(list, head)
** LIST_SPLICE_TAIL(list, head)
** Joins two lists, adding @list after(stacks)/before(queues) the element
** specified by @head. @list is reinitialized
** @list:		the &t_list_head pointer of the head of the list to add
** @head:		the &t_list_head pointer of the element to add it before/after
*/
# define LIST_SPLICE(list, head) ft_list_splice_init(list, head)
# define LIST_SPLICE_TAIL(list, head) ft_list_splice_tail_init(list, head)

/*
**LIST_APPLY(priv, type, mb, head, func)
**LIST_APPLY_REV(priv, type, mb, head, func)
**
** Use LIST_APPLY / LIST_APPLY_REV to apply a function to every element
** in the list in the forward / reverse order
** NOTE: LFA and LFAR are here to trick the 42 coding style and should not being
** used outside of here
** @priv:		private data, opaque to LIST_APPLY, passed to @f
** @type:		type of the parent structure
** @mb:			name of t_list_head within the struct
** @head:		the &t_list_head pointer of the first element of the loop
** @func:		a pointer to a function that will be applied to every element
**				of the list, which should be of prototype:
**					int foo(void *priv, void *ptr, int step)
**					@priv:	private data, opaque to LIST_APPLY, passed to @f
**					@ptr:	a void pointer the current entry of the list
**					@step:	an integer that represents the number of elements
**							processed in the loop (starts at 0)
**					@return: 1 to stop the loop, 0 to keep going
** @return:		1 if the loop was stopped, 0 if it went through
*/
# define LIST_APPLY(priv, type, mb, head, f) LA(priv, type, mb, head, f)
# define LIST_APPLY_REV(priv, type, mb, head, f) LAR(priv, type, mb, head, f)

/*
** The t_list_head structure to include as part of you list entries.
** Most functions/macros take this as arguments. You can access the parent
** structure from a &t_list_head pointer using the LIST_ENTRY macro.
*/
typedef struct			s_list_head
{
	struct s_list_head	*next;
	struct s_list_head	*prev;
}						t_list_head;

/*
** INCLUDED FUNCTIONS - See the corresponding .c files
*/
void					ft_init_list_head(t_list_head *list_head);

void					ft_list_add(t_list_head *new, t_list_head *head);
void					ft_list_add_tail(t_list_head *new, t_list_head *head);

void					ft_list_del(t_list_head *entry);

void					ft_list_replace(t_list_head *old, t_list_head *new);
void					ft_list_replace_init(t_list_head *old,
										t_list_head *new);
void					ft_list_swap(t_list_head *first, t_list_head *second);

void					ft_list_move(t_list_head *list, t_list_head *head);
void					ft_list_move_tail(t_list_head *list, t_list_head *head);

void					ft_list_rotate_left(t_list_head *head);
void					ft_list_rotate_right(t_list_head *head);

int						ft_list_is_last(const t_list_head *list,
										const t_list_head *head);
int						ft_list_empty(const t_list_head *head);
int						ft_list_empty_careful(const t_list_head *head);
int						ft_list_is_singular(const t_list_head *head);

void					ft_list_cut_position(t_list_head *list,
										t_list_head *head,
										t_list_head *entry);
void					ft_list_cut_before(t_list_head *list,
										t_list_head *head,
										t_list_head *entry);

void					ft_list_splice(const t_list_head *list,
										t_list_head *head);
void					ft_list_splice_tail(t_list_head *list,
										t_list_head *head);
void					ft_list_splice_init(t_list_head *list,
										t_list_head *head);
void					ft_list_splice_tail_init(t_list_head *list,
										t_list_head *head);

int						ft_list_apply(void *priv,
										t_list_head *head,
										unsigned long offset,
										int (*func)(void *, void *, int));
int						ft_list_apply_rev(void *priv,
										t_list_head *head,
										unsigned long offset,
										int (*func)(void *, void *, int));

#endif
