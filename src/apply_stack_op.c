/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_stack_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 23:05:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 04:51:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void				apply_stack_op
	(t_stack_op *op, t_list **a, t_list **b, t_ps_conf *c)
{
	ft_putendl(op->name);
	if (!op->arg_order)
		op->f(a, b);
	else
		op->f(b, a);
	if (c && !vect_add(c->log, op, sizeof(*op)))
		ps_exit();
	display_both_stacks(*a, *b);
}

void				apply
	(unsigned long n, t_list **a, t_list **b, t_ps_conf *c)
{
	t_stack_op		*op;
	unsigned int	times;
	unsigned int	i;

	times = n & (unsigned long)0xFFFF;
	n >>= 16;
	i = n;
	if (!times)
		times = 1;
	op = &g_stack_ops[i];
	while (times)
	{
		apply_stack_op(op, a, b, c);
		times--;
	}
}
