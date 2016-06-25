/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_stack_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 23:05:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 10:06:57 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int					apply_stack_op
	(t_stack_op *op, t_list **a, t_list **b, t_ps_conf *c)
{
	int				log;

	if (!op->arg_order)
		log = op->f(a, b);
	else
		log = op->f(b, a);
	if (log && c && !vect_add(c->log, op, sizeof(*op)))
		ps_exit();
	ft_putstr(op->name);
	ft_putendl(log ? "" : " not performed");
	display_both_stacks(*a, *b);
	return (log);
}

int					apply
	(unsigned long n, t_list **a, t_list **b, t_ps_conf *c)
{
	t_stack_op		*op;
	unsigned int	times;
	unsigned int	i;
	int				ret;

	times = n & (unsigned long)0xFFFF;
	n >>= 16;
	i = n;
	if (!times)
		times = 1;
	op = &g_stack_ops[i];
	ret = 0;
	while (times)
	{
		ret += apply_stack_op(op, a, b, c);
		times--;
	}
	return (1);
}
