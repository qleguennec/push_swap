/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:53:06 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 18:37:38 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	err(void)
{
	ft_putendl("Error");
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!(a = build_stack(argc, argv)))
		return err();
	b = NULL;
	display_stack(a);
	return (0);
}
