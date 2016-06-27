/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:08:52 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/27 13:56:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <libvect.h>
# include <stdio.h>
# include <assert.h>

typedef struct		s_lst
{
	int				data;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_stack
{
	t_lst			*head;
	t_lst			*last;
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
	unsigned int	verbose : 1;
	size_t			n_elems;
	t_vect			*log;
}					t_ps_conf;

void				ps_exit(void);
t_stack				*build_stack(char **arg);
void				display_stack(t_stack *s);
void				display_both_stacks(t_stack *a, t_stack *b);
int					apply_stack_op
(t_stack_op *op, t_stack *a, t_stack *b, t_ps_conf *c);
int					apply
	(unsigned long n, t_stack *a, t_stack *b, t_ps_conf *c);
int					stack_s(t_stack *s, t_stack *null);
int					stack_ss(t_stack *a, t_stack *b);
int					stack_r(t_stack *s, t_stack *null);
int					stack_rr(t_stack *a, t_stack *b);
int					stack_rev_r(t_stack *s, t_stack *null);
int					stack_rev_rr(t_stack *a, t_stack *b);
int					stack_p(t_stack *a, t_stack *b);
int					lcmp(t_lst *a, t_lst *b);
int					check_sorted(t_lst *a);
int					check_revsorted(t_lst *a);
int					check_lcmp(int x, t_lst *a, t_lst *cmp);
int					sort_quicksort(t_stack *a, t_stack *b, t_ps_conf *c);

# define OP(x)	apply(x, a, b, c)
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
