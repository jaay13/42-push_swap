/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:49:57 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/08 18:17:50 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

*/

#include "../inc/push_swap.h"

static void	push(t_stack *src, t_stack *dst);

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*node_to_be_pushed;

	if (!src->top)
		return ;
	node_to_be_pushed = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	node_to_be_pushed->prev = NULL;
	if (!dst->top)
	{
		dst->top = node_to_be_pushed;
		dst->bottom = node_to_be_pushed;
		node_to_be_pushed->next = NULL;
	}
	else
	{
		node_to_be_pushed->next = dst->top;
		node_to_be_pushed->next->prev = node_to_be_pushed;
		dst->top = node_to_be_pushed;
	}
}