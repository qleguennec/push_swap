/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 18:34:50 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/26 22:41:09 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// remove assertions and reverse print

#include <push_swap.h>

void		display_stack
	(t_stack *s)
{
	t_lst	*start;
	t_lst	*end;

	assert(s);
	if (!s->head)
	{
		assert(!s->last);
		ft_putchar('\n');
		return ;
	}
	start = s->head;
	end = s->last;
	while (start)
	{
		ft_putnbr(start->data);
		ft_putchar(start->next ? ' ' : '\t');
		start = start->next;
	}
	while (end)
	{
		ft_putnbr(end->data);
		ft_putchar(end->prev ? ' ' : '\n');
		end = end->prev;
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
