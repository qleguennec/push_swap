/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 22:36:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/05 23:26:06 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_stack		*sort_pre
	(t_node *n)
{
	t_stack	*ret;

	if (!(ret = ft_memalloc(sizeof(*ret))))
		ps_exit();
	while (n)
	{
		stack_insert_sorted(ret, n);
		n = n->next;
	}
	return (ret);
}
