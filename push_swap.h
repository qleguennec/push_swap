/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:08:52 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/05 23:22:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libvect/libvect.h"
# include <stdio.h>
# include <assert.h>

typedef struct		s_node
{
	int				data;
	char			tok;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	t_node			*head;
	t_node			*last;
	size_t			size;
}					t_stack;

typedef struct		s_stack_op
{
	char			name[4];
	int				(*f)(t_stack *, t_stack *);
	unsigned int	arg_order : 1;
}					t_stack_op;

typedef struct		s_ps_conf
{
	t_vect			*log;
	t_stack			*sorted;
}					t_ps_conf;

typedef struct		s_qsort
{
	size_t			low;
	size_t			high;
}					t_qsort;

void				ps_exit(void);
int					stack_s(t_stack *s, t_stack *null);
int					stack_ss(t_stack *a, t_stack *b);
int					stack_r(t_stack *s, t_stack *null);
int					stack_rr(t_stack *a, t_stack *b);
int					stack_rev_r(t_stack *s, t_stack *null);
int					stack_rev_rr(t_stack *a, t_stack *b);
int					stack_p(t_stack *a, t_stack *b);
t_stack				*stack_build(char **arg);
void				stack_display(t_stack *s);
void				stack_display_both(t_stack *a, t_stack *b);
int					stack_apply_op(t_stack_op *op, t_stack *a, t_stack *b);
int					stack_apply(int n, t_stack *a, t_stack *b, t_ps_conf *c);
void				stack_display_ops(t_vect *log);
void				stack_insert_sorted(t_stack *s, t_node *n);
int					cmp(t_node *a, t_node *b);
int					cmp_front(int x, t_node *a, t_node *cmp);
int					cmp_back(int x, t_node *a, t_node *cmp);
int					sorted(t_node *n);
int					rev_sorted(t_node *n);
int					sort_quick(t_stack *a, t_stack *b, t_ps_conf *c);
t_stack				*sort_pre(t_node *n);
int					log_reduce(int new, t_vect *l);

# define OP(x)	stack_apply(x, a, b, c)
# define PA		0
# define PB		1
# define RA		2
# define RB		3
# define RR		4
# define RRA	5
# define RRB	6
# define RRR	7
# define SA		8
# define SB		9
# define SS		10

static t_stack_op	g_stack_ops[] =
{
	{"pa", &stack_p, 1},
	{"pb", &stack_p, 0},
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
