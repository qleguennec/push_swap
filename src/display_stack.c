/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 18:34:50 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/27 01:17:08 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// remove assertions and reverse print

#include <push_swap.h>

void		display_stack
	(t_stack *s)
{
	t_lst	*start;

	assert(s);
	if (!s->head)
	{
		assert(!s->last);
		ft_putchar('\n');
		return ;
	}
	start = s->head;
	while (start)
	{
		ft_putnbr(start->data);
		ft_putchar(start->next ? ' ' : '\n');
		start = start->next;
	}
}

void		display_both_stacks
	(t_stack *a, t_stack *b)
{
	ft_putstr("\t");
	display_stack(a);
	ft_putstr("\t");
	display_stack(b);
}
