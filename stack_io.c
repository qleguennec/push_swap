/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 18:34:50 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 00:43:54 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// remove assertions and reverse print

#include "libft/libft.h"
#include "push_swap.h"

void		stack_display
	(t_stack *s)
{
	t_node	*start;

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

void		stack_display_both
	(t_stack *a, t_stack *b)
{
	ft_putstr("\t");
	stack_display(a);
	ft_putstr("\t");
	stack_display(b);
}
