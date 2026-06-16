/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:20:13 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/16 14:51:39 by jakoch           ###   ########.fr       */
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
	ft_printf("ra\n");
}

void rb(t_stack *b, t_config *config)
{
	rotate(b);
	config->total_ops++;
	config->rb++;
	ft_printf("rb\n");
}

void rr(t_stack *a, t_stack *b, t_config *config)
{
	rotate(a);
	rotate(b);
	config->total_ops++;
	config->rr++;
	ft_printf("rr\n");
}

static void rotate(t_stack *stack)
{
	t_node *node_to_be_rotated;
	
	if (!stack->top || !stack->top->next)		// checks if stack is empty, or has only one node
		return ;									
												// eg.: TOP/NULL <-> [1] <-> [2] <-> [3] <-> BOTTOM/NULL
	node_to_be_rotated = stack->top;			// node to be rotated points now to the stack top node 1 
	stack->top = node_to_be_rotated->next;		// TOP -> [2]  	 link stack top to new top node 2
	stack->top->prev = NULL;					// NULL <- [2]   unlink prev from top node 2
	node_to_be_rotated->next = NULL;			// [1] -> NULL 	 unlink next from node 1 (this node will be at the bottom)
	node_to_be_rotated->prev = stack->bottom;	// [3] <- [1]	 link prev from old top node 1 to current stack bottom node 3
	stack->bottom->next = node_to_be_rotated;	// [3] -> [1]    link next from current stack bottom node 3 to becoming bottom node 1
	stack->bottom = node_to_be_rotated;			// [1] <- BOTTOM link new stack bottom to node 1 becoming the new bottom node
												// now: TOP/NULL <-> [2] <-> [3] <-> [1] <-> BOTTOM/NULL
}