/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:42:20 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/15 12:53:51 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Dedicated file for sort algorithm utility functions.
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