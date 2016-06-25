/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_combined.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 22:43:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 22:58:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		stack_ss
	(t_list **a, t_list **b)
{
	stack_s(a, NULL);
	stack_s(b, NULL);
}

void		stack_rr
	(t_list **a, t_list **b)
{
	stack_r(a, NULL);
	stack_r(b, NULL);
}

void		stack_rev_rr
	(t_list **a, t_list **b)
{
	stack_rev_r(a, NULL);
	stack_rev_r(b, NULL);
}
