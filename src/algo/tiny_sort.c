/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:17:43 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/10 16:30:59 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/push_swap.h"

static void	sort_three(t_stack *a);
static void	sort_five(t_stack *a, t_stack *b);

void	tiny_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 5)
		sort_five(a, b);
}

static void	sort_three(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->bottom->value;
	if (top < bottom && middle < bottom) 				// is bottom the biggest?
		sa(a);											// does work because the other option e.g 1,2,3 is already filtered out by disorder 0
	else if (top < middle && middle > bottom) 			// is middle the biggest?
	{
		rra(a);
		if (a->top->value > a->top->next->value) 		// updated top > middle
			sa(a);
	}
	else 												// top is the biggest
	{
		ra(a);
		if (a->top->value > a->top->next->value)	 	// updated top > middle
			sa(a);
	}
}
static void	bring_min_to_top_of(t_stack *a)
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
			ra(a);										// ra as min value closer to the top
	else
		while (a->top->value != min_value)					
			rra(a);										// rra as min value is closer to the bottom
}

static void	sort_five(t_stack *a, t_stack *b)
{
	bring_min_to_top_of(a);						
	pb(a, b);											// push smallest value to stack b
	bring_min_to_top_of(a);
	pb(a, b);
	sort_three(a);
	pa(a , b);											// push them back to a
	pa(a, b);
}


