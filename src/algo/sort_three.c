/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:17:43 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/15 19:42:18 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/push_swap.h"

void	sort_three(t_stack *a, t_config *config)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->bottom->value;
	if (top < middle && middle < bottom)				// already sorted
		return ;
	if (top < bottom && middle < bottom) 				// is bottom the biggest?
		sa(a, config);
	else if (top < middle && middle > bottom) 			// is middle the biggest?
	{
		rra(a, config);
		if (a->top->value > a->top->next->value) 		// updated top > middle
			sa(a, config);
	}
	else 												// top is the biggest
	{
		ra(a, config);
		if (a->top->value > a->top->next->value)	 	// updated top > middle
			sa(a, config);
	}
}
