/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 20:10:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/29 23:51:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// remove assertions

int			stack_s
	(t_stack *s, t_stack *null)
{
	t_node	*tmp;

	(void)null;
	if (s->size < 2)
		return (0);
	if (s->head->next == s->last)
		s->last = s->head;
	tmp = s->head;
	s->head = s->head->next;
	tmp->next = s->head->next;
	tmp->prev = s->head;
	s->head->next = tmp;
	s->head->prev = NULL;
	if (s->head->next->next)
		s->head->next->next->prev = s->head->next;
	assert(!s->last->next);
	return (1);
}

int			stack_p
	(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (!a->size)
		return (0);
	a->size--;
	b->size++;
	tmp = a->head;
	if (a->head->next && a->head->next->next)
		a->head->next->prev = tmp->next;
	a->head = tmp->next;
	if (a->head)
		a->head->prev = NULL;
	else
		a->last = NULL;
	tmp->next = b->head;
	b->head = tmp;
	if (b->head->next)
		b->head->next->prev = b->head;
	else
		b->last = b->head;
	assert(!b->last->next);
	assert(!b->head->prev);
	return (1);
}

int			stack_r
	(t_stack *s, t_stack *null)
{
	t_node	*tmp;

	(void)null;
	if (s->size < 2)
		return (0);
	if (!s->head->next->next)
		return (stack_s(s, NULL));
	tmp = s->head;
	tmp->prev = s->last;
	tmp->next = s->head->next;
	s->head = s->last;
	s->head->next = tmp;
	s->last = s->last->prev;
	s->head->prev = NULL;
	s->last->next = NULL;
	return (1);
}

int			stack_rev_r
	(t_stack *s, t_stack *null)
{
	t_node	*tmp;

	(void)null;
	if (s->size < 2)
		return (0);
	if (!s->head->next->next)
		return (stack_s(s, NULL));
	tmp = s->last;
	tmp->next = s->head;
	tmp->prev = s->last->prev;
	s->last = s->head;
	s->last->prev = tmp;
	s->head = s->head->next;
	s->head->prev = NULL;
	s->last->next = NULL;
	return (1);
}
