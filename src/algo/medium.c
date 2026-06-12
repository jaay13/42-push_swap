/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:54:00 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/12 18:34:10 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*

Chunk-based sorting (divide into √n chunks)
Collect and store all values from a in a copy DONE
sort copies DONE
turn each value to a rank 0 -> n - 1 (n = amount of numbers in total) CURRENTLY 
Push based on √n chunks TODO
Look at a
Start from a->top
check rank of value, push b when in top ranks, if not ra until a value from chunk 1 comes to the top
optionally rb if in lower half of chunk
repeat until a empty
while b is not empty
move max value in b to top of b
pa 

*/

void	medium_sort(t_stack *a, t_stack *b)
{
	int *copy_of_stack;
	t_node *current;
	int i;
	int j;
	int temp;
	int min_index;
	int chunk_size;
	int chunk_start;
	int chunk_end;
	int chunk_count;
	int pushed;
	int chunk_mid;
	int top_value;
	int a_size;
	
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else
	{
		copy_of_stack = malloc(sizeof(int) * a->size);
		if (!copy_of_stack)
			return ;
		current = a->top;
		i = 0;
		while (current)
		{
			copy_of_stack[i++] = current->value;						// copy stack a node values into an array
			current = current->next;
		}
		i = 0;
		while (i < a->size - 1)											// Go through the array
		{
			min_index = i;
			j = i + 1;
			while (j < a->size)
			{
				if (copy_of_stack[j] < copy_of_stack[min_index])		// if the current min value is bigger then the value at current index
					min_index = j;										// set to new min value index
				j++;
			}
			if (min_index != i)											// if the found min value index differs from the one before
			{
				temp = copy_of_stack[i];
				copy_of_stack[i] = copy_of_stack[min_index];			// swap them
				copy_of_stack[min_index] = temp;
			}															// copy_of_stack will now have a sorted array with stack a values
			i++;
		}
		current = a->top;												// reset current node
		i = 0;
		while (current)										
		{
			i = 0;
			while (i < a->size)
			{
				if (current->value == copy_of_stack[i])					// Assign rank values based on the index, comparing against the sorted array
				{
					current->value = i;									// overwrites a stack values with ranks
					break;		
				}
				else
					i++;
			}
			current = current->next;
		}
		a_size = a->size;
		chunk_size = (int)sqrt(a_size) + 1;    			// √n chunks, +1 avoiding undersizing the chunk
		chunk_start = 0;
		chunk_end = chunk_size - 1;
		pushed = 0;
		while (a->top)
		{
			chunk_count = chunk_end - chunk_start + 1;
			while (pushed < chunk_count)
			{
				if (a->top->value >= chunk_start && a->top->value <= chunk_end)
				{
					top_value = a->top->value;
					pb(a, b);
					chunk_mid = (chunk_start + chunk_end) / 2;
					if (chunk_mid >= top_value && b->size > 1)
						rb(b);
					pushed++;
				}
				else
					ra(a);
			}
			pushed = 0;
			chunk_start += chunk_size;
			chunk_end += chunk_size;
			if (chunk_end > a_size - 1)
				chunk_end = a_size - 1;
		}
		push_max_chunks_to(a, b);
		free(copy_of_stack);
	}
}
