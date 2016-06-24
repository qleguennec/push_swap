/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:08:52 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 21:53:40 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

t_list					*build_stack(char **start, char **end);
void					display_stack(t_list *s);
void					stack_swap(t_list **s);
void					stack_rotate(t_list **s);
void					stack_rev_rotate(t_list **s);
void					stack_push(t_list **a, t_list **b);

#endif
