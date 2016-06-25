/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:08:52 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 04:51:37 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <libvect.h>
# include <stdio.h>

typedef struct		s_stack_op
{
	char			name[4];
	void			(*f)(t_list **, t_list **);
	unsigned int	arg_order : 1;
}					t_stack_op;

typedef struct		s_ps_conf
{
	unsigned int	verbose : 1;
	size_t			n_elems;
	t_vect			*log;
}					t_ps_conf;

void				ps_exit(void);
t_list				*build_stack(char **arg);
void				display_stack(t_list *s);
void				display_both_stacks(t_list *a, t_list *b);
void				apply_stack_op
(t_stack_op *op, t_list **a, t_list **b, t_ps_conf *c);
void				apply(unsigned long, t_list **a, t_list **b, t_ps_conf *c);
void				stack_s(t_list **s, t_list **null);
void				stack_ss(t_list **a, t_list **b);
void				stack_r(t_list **s, t_list **null);
void				stack_rr(t_list **a, t_list **b);
void				stack_rev_r(t_list **s, t_list **null);
void				stack_rev_rr(t_list **a, t_list **b);
void				stack_p(t_list **a, t_list **b);
int					lcmp(t_list *a, t_list *b);
int					check_sorted(t_list *a);
void				sort_quicksort(t_list **a, t_list **b, t_ps_conf *c);

# define PA		0
# define PB		(1 << 16)
# define RA		(2 << 16)
# define RB		(3 << 16)
# define RR		(4 << 16)
# define RRA	(5 << 16)
# define RRB	(6 << 16)
# define RRR	(7 << 18)
# define SA		(8 << 16)
# define SB		(9 << 16)
# define SS		(10 << 16)

static t_stack_op	g_stack_ops[] =
{
	{"pa", &stack_p, 0},
	{"pb", &stack_p, 1},
	{"ra", &stack_r, 0},
	{"rb", &stack_r, 1},
	{"rr", &stack_rr, 0},
	{"rra", &stack_rev_r, 0},
	{"rrb", &stack_rev_r, 1},
	{"rrr", &stack_rev_rr, 0},
	{"sa", &stack_s, 0},
	{"sb", &stack_s, 1},
	{"ss", &stack_ss, 0},
};

#endif
