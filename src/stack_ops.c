/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 20:10:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 22:57:26 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		stack_s
	(t_list **s, t_list **null)
{
	t_list	*buf;

	(void)null;
	if (!*s || !(*s)->next)
		return ;
	buf = *s;
	*s = buf->next;
	buf->next = (*s)->next;
	(*s)->next = buf;
}

void		stack_p
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

void		stack_r
	(t_list **s, t_list **null)
{
	(void)null;
	if (!*s)
		return ;
	if ((*s)->next)
	{
		stack_s(s, NULL);
		stack_r(&(*s)->next, NULL);
	}
}

void		stack_rev_r
	(t_list **s, t_list **null)
{
	(void)null;
	if (!*s || !(*s)->next)
		return ;
	if ((*s)->next->next)
		stack_rev_r(&(*s)->next, NULL);
	stack_s(s, NULL);
}
