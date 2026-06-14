/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:21:57 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/14 17:42:26 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	append_node(t_stack *stack, t_node *node)
{
	if (!node)
		return;
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		stack->bottom->next = node;
		node->next = NULL;
		node->prev = stack->bottom;
		stack->bottom = node;
	}
}

void	bring_min_to_top_of(t_stack *a, t_config *config)
{
	t_node *current;
	int min_value;
	int min_value_index;
	int i;

	current = a->top;									
	min_value = current->value;
	min_value_index = 0;
	i = 0;
	while (current)										// walk the nodes in stack a
	{
		if (current->value < min_value)					// update min value and index
		{
			min_value = current->value;
			min_value_index = i;
		}
		i++;
		current = current->next;						// go onto the next node
	}
	if (min_value_index <= a->size / 2)					// is the min value in the top half or bottom half?  a->size gives total nodes / 2 gives the middle, anything below that = closer to the top
		while (a->top->value != min_value)					
			ra(a, config);								// ra as min value closer to the top
	else
		while (a->top->value != min_value)					
			rra(a, config);								// rra as min value is closer to the bottom
}
void	bring_max_to_top_of(t_stack *b, t_config *config)
{
	t_node	*current;
	int		max_value;
	int		max_value_index;
	int		i;

	if (!b || !b->top)
		return ;
	current = b->top;
	max_value = current->value;
	max_value_index = 0;
	i = 0;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_value_index = i;
		}
		i++;
		current = current->next;
	}
	if (max_value_index <= b->size / 2)
		while (b->top->value != max_value)
			rb(b, config);
	else
		while (b->top->value != max_value)
			rrb(b, config);
}

void	push_max_chunks_to_a(t_stack *a, t_stack *b, t_config *config)
{
	while (b->top)
	{
		bring_max_to_top_of(b, config);
		pa(a, b, config);
	}
}
