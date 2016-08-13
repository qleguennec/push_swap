/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 18:34:50 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/08 14:31:17 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// remove assertions and reverse print

#include "push_swap.h"

void		stack_display
	(t_stack *s, t_ps_conf *c)
{
	t_node	*start;

	assert(s);
	if (!s->head)
	{
		assert(!s->last);
		vect_mset_end(c->log, '\n', 1);
		return ;
	}
	start = s->head;
	while (start)
	{
		vect_fmt(c->log, "%d%c", start->data, start->next ? ' ' : '\n');
		start = start->next;
	}
}

void		stack_display_both
	(t_stack *a, t_stack *b, t_ps_conf *c)
{
	vect_addstr(c->log, "\033[0;31m\t");
	stack_display(a, c);
	vect_addstr(c->log, "\033[0;32m\t");
	stack_display(b, c);
	vect_addstr(c->log, "\033[0m");
}
