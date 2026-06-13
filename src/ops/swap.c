/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:03:24 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/13 12:56:11 by jakoch           ###   ########.fr       */
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

	if (!stack->top || !stack->top->next)		// checks if stack a is empty, or has only one node
		return;
	node1 = stack->top;					
	node2 = node1->next;
	node3 = node2->next;
	if (node3)									// checks if there is more than 2 nodes
	{
		node3->prev = node1;
		node1->next = node3;
	}
	else
	{
		stack->bottom = node1;
		node1->next = NULL;
	}
	node1->prev = node2;				
	node2->next = node1;
	node2->prev = NULL;
	stack->top = node2;
}
