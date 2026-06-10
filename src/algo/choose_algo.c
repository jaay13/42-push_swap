/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:04:18 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/10 14:09:27 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	choose_algo(t_stack *a, t_stack *b, t_config *config)
{
	if (a->size <= 5)
		tiny_sort(a, b);
	if (config->strategy == SIMPLE)
		simple_sort(a, b);
	else if (config->strategy == MEDIUM)
		medium_sort(a, b);
	else
		complex_sort(a, b);
}

