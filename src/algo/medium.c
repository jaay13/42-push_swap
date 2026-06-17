/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:54:00 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 20:17:53 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Chunk-based sorting (divide into √n chunks)
Collect and store all values from a in a copy
sort copies
turn each value to a rank 0 -> n - 1 (n = amount of numbers in total)
Push based on √n chunks
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
static void	push_max_values_back_to_a(t_stack *a, t_stack *b, t_config *config);

void	medium_sort(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size <= 5)
		tiny_sort(a, b, config);
	else
	{
		rank_stack_values_of(a, config);
		push_chunks_to_b(a, b, config);
		push_max_values_back_to_a(a, b, config);
	}
}

static void	push_chunk_value_to_b(t_stack *a, t_stack *b, t_config *config, int chunk_start, int chunk_end, int *pushed)
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

static void	update_chunk(int *chunk_start, int *chunk_end, int chunk_size, int a_size)
{
	*chunk_start += chunk_size;
	*chunk_end += chunk_size;
	if (*chunk_end > a_size - 1)
		*chunk_end = a_size - 1;
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
	chunk_size = (int)sqrt(a_size) * 3;
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

static void	push_max_values_back_to_a(t_stack *a, t_stack *b, t_config *config)
{
	while (b->top)
	{
		bring_max_to_top_of(b, config);
		pa(a, b, config);
	}
}

