/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 20:10:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 10:13:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			stack_s
	(t_list **s, t_list **null)
{
	t_list	*buf;

	(void)null;
	if (!*s || !(*s)->next)
		return (0);
	buf = *s;
	*s = buf->next;
	buf->next = (*s)->next;
	(*s)->next = buf;
	return (1);
}

int			stack_p
	(t_list **a, t_list **b)
{
	t_list	*elem;

	if (!*a)
		return (0);
	elem = *a;
	*a = elem->next;
	elem->next = *b;
	*b = elem;
	return (1);
}

int			stack_r
	(t_list **s, t_list **null)
{
	(void)null;
	if (!*s || !(*s)->next)
		return (0);
	if ((*s)->next)
	{
		stack_s(s, NULL);
		stack_r(&(*s)->next, NULL);
	}
	return (1);
}

int			stack_rev_r
	(t_list **s, t_list **null)
{
	(void)null;
	if (!*s || !(*s)->next)
		return (0);
	if ((*s)->next->next)
		stack_rev_r(&(*s)->next, NULL);
	stack_s(s, NULL);
	return (1);
}
