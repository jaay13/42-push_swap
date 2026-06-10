/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:10:35 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/10 10:51:44 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	compute_disorder(t_stack *a, t_config *config)
{
	int mistakes;
	int total_pairs;
	t_node *node1;
	t_node *node2;

	mistakes = 0;
	total_pairs = 0;
	node1 = a->top;
	while(node1)
	{
		node2 = node1->next;
		while(node2)
		{
			total_pairs++;
			if (node1->value > node2->value)
				mistakes++;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	config->disorder = (float)mistakes/ total_pairs;
	if (config->disorder == 0.0f)							// check if disorder 0 (fully sorted), exit
		exit(0);
}

void	strategy_picker(t_config *config)
{
	if (config->strategy_picked == true)
	{
		if (config->disorder < 0.2f)
			config->strategy = SIMPLE;
		else if (config->disorder >= 0.2f && config->disorder < 0.5f)
			config->strategy = MEDIUM;
		else
			config->strategy = COMPLEX;
	}
}