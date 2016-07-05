/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_apply_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 23:05:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/05 02:30:40 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
		//ft_putendl(op->name);
		//stack_display_both(a, b);
	if (!ret)
		return (1);
	return (log_reduce(n, c->log));
}

void				stack_display_ops
	(t_vect *log)
{
	t_stack_op		*op;
	int				index;
	size_t			i;
	size_t			k;
	size_t			len;

	i = 0;
	k = 0;
	while (i < log->used)
	{
		assert(k <= i);
		index = ((int *)log->data)[i / 4];
		assert(index >= PA && index <= SS || !printf("%d\n", index));
		op = &g_stack_ops[index];
		len = ft_strlen(op->name);
		ft_memcpy(log->data + k, op->name, len);
		((char *)log->data)[k + len] = '\n';
		k += len + 1;
		if (k >= BUFSIZ * 64)
		{
			write(1, log->data, k);
			k = 0;
		}
		i += sizeof(index);
	}
	write(1, log->data, k);
}
