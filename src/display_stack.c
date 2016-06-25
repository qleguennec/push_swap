/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 18:34:50 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 03:08:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		display_stack
	(t_list *s)
{
	if (!s)
	{
		ft_putchar('\n');
		return ;
	}
	while (s)
	{
		ft_putnbr((int)s->data);
		if (s->next)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		s = s->next;
	}
}

void		display_both_stacks
	(t_list *a, t_list *b)
{
	ft_putstr("A: ");
	display_stack(a);
	ft_putstr("B: ");
	display_stack(b);
}
