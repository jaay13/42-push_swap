/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:03:29 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/10 12:56:36 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack a;  								// Create stacks
	t_stack b;
	t_config config;

	if (argc == 1)
		return (0); 							// no parameters 
	stack_init(&a, 'a'); 						// initialize stack a
	stack_init(&b, 'b'); 						// init stack b
	parse_input(argc, argv, &config); 			// parse to check wether flags are present, string needs to be split, checking correct input, range and dupes
	build_stack(&a, &config); 					// build stack a
	compute_disorder(&a, &config);				// compute disorder, check if sorted (disorder 0)
	strategy_picker(&config);					// set either forced strategy or adaptive default based on disorder
	sort_with_algo(&a, &b, &config);			// run algo
	// if (bench flag is present)
		//print_bench();	// print bench
	free_stack(&a);	// free everything
	free_stack(&b);
	return (0);
}