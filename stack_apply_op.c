/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_apply_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 23:05:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 01:51:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int					stack_apply_op
	(t_stack_op *op, t_stack *a, t_stack *b)
{
	int				ret;

	if (!op->arg_order)
		ret = op->f(a, b);
	else
		ret = op->f(b, a);
	return (ret);
}

int					stack_apply
	(int n, t_stack *a, t_stack *b, t_ps_conf *c)
{
	t_stack_op		*op;
	int				ret;
	unsigned char	index;

	assert(c && c->log);
	op = &g_stack_ops[n];
	ret = stack_apply_op(op, a, b);
	index = n;
	if (!(vect_add(c->log, &index, 1)))
		ps_exit();
	return (1);
}

void				stack_display_ops
	(t_vect *log)
{
	t_stack_op		*op;
	size_t			i;

	i = 0;
	while (i < log->used)
	{
		op = &g_stack_ops[(int)((unsigned char *)log->data)[i++]];
		ft_putendl((char *)op);
	}
}
