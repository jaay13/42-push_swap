/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:52:30 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 17:02:11 by jakoch           ###   ########.fr       */
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

void rra(t_stack *a, t_config *config)
{
	reverse_rotate(a);
	if (!config->checker)
	{
		config->total_ops++;
		config->rra++;
		ft_printf("rra\n");
	}
	
}
void rrb(t_stack *b, t_config *config)
{
	reverse_rotate(b);
	if (!config->checker)
	{
		config->total_ops++;
		config->rrb++;
		ft_printf("rrb\n");
	}

}
void rrr(t_stack *a, t_stack *b, t_config *config)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!config->checker)
	{
		config->total_ops++;
		config->rrr++;
		ft_printf("rrr\n");
	}
}
	

static void reverse_rotate(t_stack *stack)
{
	t_node *node_to_be_rotated;
	
	if (!stack->top || !stack->top->next)		// checks if stack is empty, or has only one node
		return;									
												// eg.: TOP/NULL <-> [1] <-> [2] <-> [3] <-> BOTTOM/NULL
	node_to_be_rotated = stack->bottom;			// node to be rotated points now to the current bottom node [3]
	stack->bottom = node_to_be_rotated->prev;	// [2] <- BOTTOM  make previous node to the new bottom node
	stack->bottom->next = NULL;					// [2] -> NULL    unlink next from new bottom node [2]
	node_to_be_rotated->next = stack->top;		// [3] -> [1]     link node [3] to current top node [1]
	node_to_be_rotated->prev = NULL;			// NULL <- [3]    unlink prev from becoming top node [3]
	stack->top->prev = node_to_be_rotated;		// [3] <- [1]     link current top node 1 back to new top node [3]
	stack->top = node_to_be_rotated;			// TOP -> [3]     stack top now points to the new top node [3]
												// now: TOP/NULL <-> [3] <-> [1] <-> [2] <-> BOTTOM/NULL
}