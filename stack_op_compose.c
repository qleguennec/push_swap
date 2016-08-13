/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_combined.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 22:43:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 00:24:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			stack_ss
	(t_stack *a, t_stack *b)
{
	return (stack_s(a, NULL) + stack_s(b, NULL));
}

int			stack_rr
	(t_stack *a, t_stack *b)
{
	return (stack_r(a, NULL) + stack_r(b, NULL));
}

int			stack_rev_rr
	(t_stack *a, t_stack *b)
{
	return (stack_rev_r(a, NULL) + stack_rev_r(b, NULL));
}
