/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 20:10:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 21:46:27 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		stack_swap
	(t_list **s)
{
	t_list	*buf;

	if (!*s || !(*s)->next)
		return ;
	buf = *s;
	*s = buf->next;
	buf->next = (*s)->next;
	(*s)->next = buf;
}

void		stack_push
	(t_list **a, t_list **b)
{
	t_list	*elem;

	if (!*a)
		return ;
	elem = *a;
	*a = elem->next;
	elem->next = *b;
	*b = elem;
}

void		stack_rotate
	(t_list **s)
{
	if (!*s)
		return ;
	if ((*s)->next)
	{
		stack_swap(s);
		stack_rotate(&(*s)->next);
	}
}

void		stack_rev_rotate
	(t_list **s)
{
	if (!*s || !(*s)->next)
		return ;
	if ((*s)->next->next)
		stack_rev_rotate(&(*s)->next);
	stack_swap(s);
}
