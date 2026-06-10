/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:17:43 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/10 18:35:49 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/push_swap.h"

void	sort_three(t_stack *a);
static void	sort_four_five(t_stack *a, t_stack *b);

void	tiny_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4 || a->size == 5)
		sort_four_five(a, b);
}

void	sort_three(t_stack *a)
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

static void	sort_four_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		bring_min_to_top_of(a);						
		pb(a, b);										// push smallest value to stack b
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);										// push them back to a
}


