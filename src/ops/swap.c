/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:03:24 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/14 14:36:53 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Swap ops like sa, sb, ss

sa (swap a): Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

*/

#include "../inc/push_swap.h"

static void swap(t_stack *stack);

void sa(t_stack *a, t_config *config)
{
    swap(a);
	config->total_ops++;
	config->sa++;
    write(1, "sa\n", 3);
}

void sb(t_stack *b, t_config *config)
{
    swap(b);
	config->total_ops++;
	config->sb++;
    write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b, t_config *config)
{
    swap(a);
    swap(b);
	config->total_ops++;
	config->ss++;
    write(1, "ss\n", 3);
}

static void swap(t_stack *stack)
{
	t_node *node1;
	t_node *node2;
	t_node *node3;
												// eg.: TOP/NULL <-> [1] <-> [2] <-> [3] <-> BOTTOM/NULL
	if (!stack->top || !stack->top->next)		// checks if stack is empty, or has only one node
		return ;
	node1 = stack->top;							// node1 points to stack top node [1]
	node2 = node1->next;						// node2 points to [2]
	node3 = node2->next;						// node3 points to [3] or NULL, if only two nodes in stack
	if (node3)									// checks if there is more than 2 nodes
	{
		node3->prev = node1;					// [1] <- [3]   links prev from node 3 to top node 1  
		node1->next = node3;					// [1] -> [3]   links next from top node 1 to node 3	
	}
	else
	{
		stack->bottom = node1;					// if there aren't 3 nodes, stack bottom points now to the top node 1
		node1->next = NULL;						// unlink next from node 1 (as it's now the bottom)
	}
	node1->prev = node2;						// [2] <- [1]   links prev from current top node 1 to becoming top node 2	 
	node2->next = node1;						// [2] -> [1]   links next from becoming top node 2 to current top node 1	 
	node2->prev = NULL;							// NULL <- [2]  unlink prev from node 2 (as it's now the top)
	stack->top = node2;							// TOP -> [2]	update stack top to point to node 2, making it the new top
}												// now: TOP/NULL <-> [2] <-> [1] <-> [3] -> BOTTOM/NULL
