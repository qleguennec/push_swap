/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:08:52 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 23:08:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <libft.h>

typedef long			t_elem;
typedef t_list			t_stack;

#define ELEM_SIZE sizeof(t_elem)

t_stack					*build_stack(char **start, char **end);
void					display_stack(t_stack *s);
int						debug(t_stack **a, t_stack **b);
void					stack_swap(t_stack **s);
void					stack_rotate(t_stack **s);
void					stack_rev_rotate(t_stack **s);
void					stack_push(t_stack **a, t_stack **b);

#endif
