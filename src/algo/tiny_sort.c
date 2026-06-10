/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +#+#+#+#+#+   +#+           */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +#+#+#+#+#+   +#+           */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:30:00 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/10 13:30:00 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	tiny_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 5)
		sort_five(a, b);
}

static void sort_three(t_stack *a)
{
	int top;
	int middle;
	int bottom;

	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->bottom->value;
	if (top < bottom && middle < bottom) 			// is bottom the biggest?
		sa(a);
	else if (top < middle && middle > bottom) 		// is middle the biggest?
	{
		rra(a);
		if (a->top->value > a->top->next->value) 	// updated top > middle
			sa(a);
	}
	else 											// top is the biggest
	{
		ra(a);
		if (a->top->value > a->top->next->value) 	// updated top > middle
			sa(a);
	}
}

static void sort_five(t_stack *a, t_stack *b)
{

}
