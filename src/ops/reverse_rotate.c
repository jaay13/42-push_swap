/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:52:30 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/09 15:03:41 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.

rrr : rra and rrb at the same time.

*/

#include "../inc/push_swap.h"

static void reverse_rotate(t_stack *stack);

void rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
void rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
void rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

static void reverse_rotate(t_stack *stack)
{
	t_node *node_to_be_rotated;
	
	if (!stack->top || !stack->top->next)
		return;									
												// eg. [1][2][3]
	node_to_be_rotated = stack->bottom;			// Save node 3

	stack->bottom = node_to_be_rotated->prev;	// Set node 2 as new bottom
	stack->bottom->next = NULL;					// unlink next from new bottom node 2

	node_to_be_rotated->next = stack->top;		// link node 3 to old top node 1
	node_to_be_rotated->prev = NULL;			// node 3 becomes new top (clear prev)
	stack->top->prev = node_to_be_rotated;		// link old top node 1 back to node 3
	stack->top = node_to_be_rotated;			// set node 3 as new top
												// now [3][1][2]
}