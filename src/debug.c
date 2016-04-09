/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 19:59:30 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 23:08:05 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <unistd.h>

int			debug
	(t_stack **a, t_stack **b)
{
	char	input[4];
	size_t	nbytes;

	ft_putstr("(push_swap) ");
	nbytes = read(0, input, 4);
	if (!nbytes)
		return (0);
	if (ft_strnequ(input, "ss", 2))
	{
		stack_swap(a);
		stack_swap(b);
	}
	if (ft_strnequ(input, "sa", 2))
		stack_swap(a);
	else if (ft_strnequ(input, "sb", 2))
		stack_swap(b);
	if (ft_strnequ(input, "ra", 2))
		stack_rotate(a);
	else if (ft_strnequ(input, "rb", 2))
		stack_rotate(b);
	if (ft_strnequ(input, "rra", 3))
		stack_rev_rotate(a);
	else if (ft_strnequ(input, "rrb", 3))
		stack_rev_rotate(b);
	else if (ft_strnequ(input, "pa", 2))
		stack_push(a, b);
	else if (ft_strnequ(input, "pb", 2))
		stack_push(b, a);
	ft_putstr("A: ");
	display_stack(*a);
	ft_putstr("B: ");
	display_stack(*b);
	return (debug(a, b));
}
