/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_insert_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 22:47:12 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/06 00:17:17 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stack_insert_sorted
	(t_stack *s, t_node *n)
{
	t_node	*m;

	if (!s->size)
	{
		s->head = n;
		s->last = n;
		s->size = 1;
		return ;
	}
	assert(s->head && s->last);
	s->size++;
	if (cmp(n, s->last) >= 0)
	{
		n->prev = s->last;
		n->next = NULL;
		s->last->next = n;
		s->last = n;
		return ;
	}
	if (cmp(n, s->head) < 0)
	{
		n->prev = NULL;
		n->next = s->head;
		s->head->prev = n;
		s->head = n;
		return ;
	}
	m = s->head;
	while (!cmp_front(1, m, n))
		m = m->next;
	n->next = m;
	n->prev = m->prev;
	m->prev = n;
	return ;
}
