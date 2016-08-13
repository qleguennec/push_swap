/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_apply_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 23:05:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/26 14:29:03 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int					stack_apply_op
	(t_stack_op *op, t_stack *a, t_stack *b)
{
	return (op->arg_order ? op->f(b, a) : op->f(a, b));
}

int					stack_apply
	(int n, t_stack *a, t_stack *b, t_ps_conf *c)
{
	t_stack_op		*op;
	int				ret;

	assert(c && c->log);
	op = &g_stack_ops[n];
	ret = stack_apply_op(op, a, b);
	if (!ret)
		return (1);
	return (log_reduce(n, c->log));
}

void				stack_display_ops
	(t_ps_conf *c)
{
	t_stack_op		*op;
	int				index;
	size_t			i;
	size_t			k;
	size_t			len;

	i = 0;
	k = 0;
	while (i < c->log->used)
	{
		assert(k <= i);
		index = ((int *)c->log->data)[i / 4];
		op = &g_stack_ops[index];
		len = ft_strlen(op->name);
		ft_memcpy(c->log->data + k, op->name, len);
		((char *)c->log->data)[k + len] = '\n';
		k += len + 1;
		if (k >= BUFSIZ * 64)
		{
			write(1,c->log->data, k);
			k = 0;
		}
		i += sizeof(index);
	}
	write(1, c->log->data, k);
}
