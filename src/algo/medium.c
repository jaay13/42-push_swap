/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:54:00 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/15 14:08:04 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "../inc/push_swap.h"

static void	push_chunks_to_b(t_stack *a, t_stack *b, t_config *config);

void	medium_sort(t_stack *a, t_stack *b, t_config *config)
{
	int *copy_of_stack;
	
	if (a->size == 2)
		sa(a, config);
	else if (a->size == 3)
		sort_three(a, config);
	else
	{
		copy_of_stack = copy_stack_into_array(a);
		if (!copy_of_stack)
			return ;
		sort_array(copy_of_stack, a->size);
		turn_stack_value_into_rank(a, copy_of_stack);
		push_chunks_to_b(a, b, config);
		push_max_chunks_to_a(a, b, config);
		free(copy_of_stack);
	}
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, t_config *config)
{
	int	a_size;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;
	int	pushed;
	int	chunk_count;

	a_size = a->size;
	chunk_size = (int)sqrt(a_size) + 1;
	chunk_start = 0;
	chunk_end = chunk_size - 1;
	while (a->top)
	{
		chunk_count = chunk_end - chunk_start + 1;
		pushed = 0;
		while (pushed < chunk_count)
		{
			if (a->top->value >= chunk_start && a->top->value <= chunk_end)
				push_chunk_value_to_b(a, b, config, chunk_start, chunk_end, &pushed);
			else
				ra(a, config);
		}
		update_chunk(&chunk_start, &chunk_end, chunk_size, a_size);
	}
}
