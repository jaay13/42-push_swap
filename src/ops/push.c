/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:49:57 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/14 16:26:06 by jakoch           ###   ########.fr       */
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

void	pa(t_stack *a, t_stack *b, t_config *config)
{
	push(b, a);
	a->size++;
	b->size--;
	config->total_ops++;
	config->pa++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, t_config *config)
{
	push(a, b);
	a->size--;
	b->size++;
	config->total_ops++;
	config->pb++;
	write(1, "pb\n", 3);
}

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*node_to_be_pushed;

	if (!src->top)											// checks if stack is empty
		return ;
															// eg.: src: TOP/NULL <-> [1] <-> [2] <-> BOTTOM/NULL
															// 		dst: empty
															// 		dst: TOP/NULL <-> [3] <-> BOTTOM/NULL (eg if not empty)
	node_to_be_pushed = src->top; 							// node to be pushed now points to src top node [1]
	src->top = src->top->next;								// TOP -> [2]  	  links src top to node [2]
	if (src->top)											// checks if node [2] exists (that src still has nodes)
		src->top->prev = NULL;								// NULL <- [2]    unlink prev from new src top node [2] as its now at the top
	else													
		src->bottom = NULL;									// NULL <- BOTTOM unlink src bottom, making it empty
	node_to_be_pushed->prev = NULL;							// NULL <- [1]    unlink prev from node [1] 
	if (!dst->top)											// if dst is empty
	{
		dst->top = node_to_be_pushed;						// TOP -> [1]     links dst top to node [1] from src 
		dst->bottom = node_to_be_pushed;					// [1] <- BOTTOM  links dst bottom to node [1], making it the only node in dst 
		node_to_be_pushed->next = NULL;						// [1] -> NULL    unlink next from node [1]
	}
	else													// dst isn't empty, dst: TOP/NULL <-> [3] <-> BOTTOM/NULL
	{
		node_to_be_pushed->next = dst->top;					// [1] -> [3]	  links next from becoming top node [1] old top node [3]
		node_to_be_pushed->next->prev = node_to_be_pushed; 	// [1] <- [3]	  links prev from old top node [3] to becoming top node [1]
		dst->top = node_to_be_pushed;						// TOP -> [1]	  links dst top to node [1], making it the new top of dst
	}
															// now: src: TOP/NULL <-> [2] <-> BOTTOM/NULL
															// 		dst: TOP/NULL <-> [1] <-> BOTTOM/NULL (if it was empty)
															//		dst: TOP/NULL <-> [1] <-> [3] <-> BOTTOM/NULL (if not empty)
}