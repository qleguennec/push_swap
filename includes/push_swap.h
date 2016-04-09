/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:08:52 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 18:34:40 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <libft.h>

typedef long			t_elem;
typedef t_list			t_stack;

#define ELEM_SIZE sizeof(t_elem)

t_stack					*build_stack(int argc, char **argv);
void					display_stack(t_stack *s);

#endif
