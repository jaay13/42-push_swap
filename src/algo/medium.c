/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:54:00 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/11 19:18:13 by jakoch           ###   ########.fr       */
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

	copy_of_stack = malloc(sizeof(int) * a->size);
	if (!copy_of_stack)
		return ;
	current = a->top;
	i = 0;
	while (current)
	{
		copy_of_stack[i++] = current->value;
		current = current->next;
	}
	i = 0;
	while (i < a->size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < a->size)
		{
			if (copy_of_stack[j] < copy_of_stack[min_index])
				min_index = j;
			j++;
		}
		if (min_index != i)
		{
			temp = copy_of_stack[i];
			copy_of_stack[i] = copy_of_stack[min_index];
			copy_of_stack[min_index] = temp;
		}
		i++;
	}
	current = a->top;
	i = 0;
	while (current)
	{
		i = 0;
		while (i < a->size)
		{
			if (current->value == copy_of_stack[i])
			{
				current->value = i;
				break;
			}
			else
				i++;
		}
		current = current->next;
	}
	free(copy_of_stack);
}