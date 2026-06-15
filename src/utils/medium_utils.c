/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 17:27:24 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/15 12:54:23 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Dedicated file for medium sort utility functions.
*/

// might not need this file anymore, refactor and put in medium.c

#include "../inc/push_swap.h"

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
