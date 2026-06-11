/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +#+#+#+#+#+   +#+           */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +#+#+#+#+#+   +#+           */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:31:00 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/10 13:31:00 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* 

	Min extraction method:

	Look at the current stack a
	Find the minimum value
	Rotate a so that value reaches the top
	Push it to b
	Repeat until a is small enough to finish directly
	Sort the remaining tiny core
	Push everything back

*/

void	simple_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else
	{
		while (a->size > 3)							
		{
			bring_min_to_top_of(a);
			pb(a, b);								// push smallest value to stack b
		}
		sort_three(a);								
		while (b->size > 0)
			pa(a, b);								// push them back to a
	}
}