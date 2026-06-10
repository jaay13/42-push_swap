/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:49:57 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/10 19:22:02 by jakoch           ###   ########.fr       */
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
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*node_to_be_pushed;

	if (!src->top)											// do nothing if empty
		return ;
	node_to_be_pushed = src->top; 							// store node to push
	src->top = src->top->next;								// set new src stack top
	if (src->top)											
		src->top->prev = NULL;								// clear prev of new top
	else													
		src->bottom = NULL;									// mark src to empty
	node_to_be_pushed->prev = NULL;
	if (!dst->top)											// if dst empty
	{
		dst->top = node_to_be_pushed;						// set to new top
		dst->bottom = node_to_be_pushed;					// set to new bottom
		node_to_be_pushed->next = NULL;						
	}
	else
	{
		node_to_be_pushed->next = dst->top;					// Link new top to old 
		node_to_be_pushed->next->prev = node_to_be_pushed; 	// Link old top to new top
		dst->top = node_to_be_pushed;						// update top
	}
}