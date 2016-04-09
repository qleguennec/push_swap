/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 20:10:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 23:19:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		stack_swap
	(t_stack **s)
{
	t_stack	*buf;

	if (!*s || !(*s)->next)
		return ;
	buf = *s;
	*s = buf->next;
	buf->next = (*s)->next;
	(*s)->next = buf;
}

void		stack_push
	(t_stack **a, t_stack **b)
{
	t_stack	*elem;

	if (!*a)
		return ;
	elem = *a;
	*a = elem->next;
	elem->next = *b;
	*b = elem;
}

void		stack_rotate
	(t_stack **s)
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
	(t_stack **s)
{
	if (!*s)
		return ;
	if ((*s)->next->next)
		stack_rev_rotate(&(*s)->next);
	stack_swap(s);
}
