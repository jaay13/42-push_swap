/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 13:04:18 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/13 13:05:55 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	choose_algo(t_stack *a, t_stack *b, t_config *config)
{
	if (config->strategy == SIMPLE)
		simple_sort(a, b, config);
	else if (config->strategy == MEDIUM)
		medium_sort(a, b, config);
	else
		complex_sort(a, b, config);
}

/*  After checking the task carefully I think using a tiny sort is not what the task
 	actually wants as it says: Any selector should work regardless of input size or disorder

	which means for me at least: 
	--complex should use a complex algorithm even if input is 2, 3, 4, 5 DONE
	same for the others DONE
	means no tiny_sort rerouting allowed?
	The user should obviously know it will perform worse, but should have the freedom to choose

	TODO:
	remove tiny_sort and refactor so its task compliant DONE
	add special cases in each algorithm to handle these low inputs possible? (TODO)
	
	EXTRA:
	with this option if using --complex and --bench bench would say used complex algorithm
	which would be misleading if input is under 5 numbersd DONE

*/
