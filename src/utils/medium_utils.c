/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:27:24 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/14 17:49:34 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Dedicated file for medium sort utility functions.
*/

#include "../inc/push_swap.h"

int	*copy_stack_into_array(t_stack *a)
{
	int *copy_of_stack;
	int i;
	t_node *current;
	
	copy_of_stack = malloc(sizeof(int) * a->size);
	if (!copy_of_stack)
		return (NULL);
	current = a->top;
	i = 0;
	while (current)
	{
		copy_of_stack[i++] = current->value;						// copy stack a node values into an array
		current = current->next;
	}
	return (copy_of_stack);
}

void	sort_array(int *copied_array, int stack_size)
{
	int min_index;
	int i;
	int j;
	int temp;
	
	i = 0;
	while (i < stack_size - 1)											// Go through the array
		{
			min_index = i;
			j = i + 1;
			while (j < stack_size)
			{
				if (copied_array[j] < copied_array[min_index])		// if the current min value is bigger then the value at current index
					min_index = j;									// set to new min value index
				j++;
			}
			if (min_index != i)										// if the found min value index differs from the one before
			{
				temp = copied_array[i];
				copied_array[i] = copied_array[min_index];			// swap them
				copied_array[min_index] = temp;
			}														// copied_array will now have a sorted array with stack a values
			i++;
		}
}

void	turn_array_value_into_rank(t_stack *a, int *sorted_array)
{
	t_node *current;
	int i;

	current = a->top;												// reset current node
	i = 0;
	while (current)										
	{
		i = 0;
		while (i < a->size)
		{
			if (current->value == sorted_array[i])					// Assign rank values based on the index, comparing against the sorted array
			{
				current->value = i;									// overwrites a stack values with ranks
				break;		
			}
			else
				i++;
		}
		current = current->next;
	}
}

void	push_chunk_value_to_b(t_stack *a, t_stack *b, t_config *config, int chunk_start, int chunk_end, int *pushed)
{
	int	top_value;
	int	chunk_mid;

	top_value = a->top->value;
	pb(a, b, config);
	chunk_mid = (chunk_start + chunk_end) / 2;
	if (chunk_mid >= top_value && b->size > 1)
		rb(b, config);
	(*pushed)++;
}

void	update_chunk(int *chunk_start, int *chunk_end, int chunk_size, int a_size)
{
	*chunk_start += chunk_size;
	*chunk_end += chunk_size;
	if (*chunk_end > a_size - 1)
		*chunk_end = a_size - 1;
}
