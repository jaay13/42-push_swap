/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:20:13 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/13 12:56:31 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

ra (rotate a): Shift up all elements of stack a by one.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by one.
The first element becomes the last one.

rr : ra and rb at the same time.


*/

#include "../inc/push_swap.h"

static void rotate(t_stack *stack);

void ra(t_stack *a, t_config *config)
{
	rotate(a);
	config->total_ops++;
	config->ra++;
	write(1, "ra\n", 3);
}

void rb(t_stack *b, t_config *config)
{
	rotate(b);
	config->total_ops++;
	config->rb++;
	write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b, t_config *config)
{
	rotate(a);
	rotate(b);
	config->total_ops++;
	config->rr++;
	write(1, "rr\n", 3);
}

static void rotate(t_stack *stack)
{
	t_node *node_to_be_rotated;
	
	if (!stack->top || !stack->top->next)
		return;									
												// eg. [1][2][3]
	node_to_be_rotated = stack->top;			// Save node 1

	stack->top = node_to_be_rotated->next;		// Set node 2 as new top
	stack->top->prev = NULL;					// unlink prev from new top

	node_to_be_rotated->next = NULL;			// unlink next from node 1 to rotate as it will be at the bottom
	node_to_be_rotated->prev = stack->bottom;	// link prev from node 1 to rotate to stack bottom nodde
	stack->bottom->next = node_to_be_rotated;	// link next from old stack bottom node to node 1
	stack->bottom = node_to_be_rotated;			// set new stack bottom (node 1)
												// now [2][3][1]
}