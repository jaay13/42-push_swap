/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:54:11 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/15 12:55:07 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Radix sort adaptation (bitwise sorting with two stacks)
Copy all values from a into an array DONE
sort / normalize values into ranks 0 -> n - 1 DONE
find max rank and number of bits needed TODO
for each bit position from 0 to max_bits - 1 TODO
start from top of a
if current value has bit 0 at this position, pb to b
if current value has bit 1 at this position, ra
repeat until all values in a were checked
while b is not empty, pa back to a
repeat for next bit
after last bit, stack a is sorted

*/


#include "../inc/push_swap.h"

void	complex_sort(t_stack *a, t_stack *b, t_config *config)
{
	int *copy_of_stack;
	copy_of_stack = copy_stack_into_array(a);
	if (!copy_of_stack)
			return ;
	sort_array(copy_of_stack, a->size);
	turn_array_value_into_rank(a, copy_of_stack);
	find_max_rank_and_bits(copy_of_stack);
	push_or_ra(a, copy_of_stack);
	free(copy_of_stack);
}
