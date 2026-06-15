/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:54:11 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/15 14:41:57 by jakoch           ###   ########.fr       */
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

int		find_max_bits(int max_value_of_stack);
void	push_or_ra(t_stack *a, t_stack *b, t_config *config, int bit);

void	complex_sort(t_stack *a, t_stack *b, t_config *config)
{
	int *copy_of_stack;
	int i;
	int j;
	int max_bits;
	int size_a;
	
	size_a = a->size;
	i = 0;
	copy_of_stack = copy_stack_into_array(a);
	if (!copy_of_stack)
			return ;
	sort_array(copy_of_stack, size_a);
	turn_stack_value_into_rank(a, copy_of_stack);
	max_bits = find_max_bits(size_a - 1);
	while (i < max_bits)
	{
		j = 0;
		while (j < size_a)
		{
			push_or_ra(a, b, config, i);
			j++;
		}
		while (b->top)
			pa(a, b, config);
		i++;
	}
	free(copy_of_stack);
}

int	find_max_bits(int max_value_of_stack)
{
	int bits;

	bits = 0;
	while (max_value_of_stack >> bits)			// while max_value shifted right by amount of bits isn't 0 
		bits++;									// 5 >> 0 = 5, 5 >> 1 = 2, 5 >> 2 = 1, 5 >> 3 = 0 => max bits = 3 (5 = 101 in binary)
	return (bits);
}

void	push_or_ra(t_stack *a, t_stack *b, t_config *config, int bit)
{
	if (((a->top->value >> bit) & 1) == 0)		// shift a top value right by bit positions, &1 keep only the last bit, == 0 check wether that bit is 0
		pb(a, b, config);
	else
		ra(a, config);
}
