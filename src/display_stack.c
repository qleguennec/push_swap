/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 18:34:50 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 21:46:49 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
