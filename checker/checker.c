/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:56:23 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 14:00:21 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack a;  								// Create stacks
	t_stack b;
	t_config config;

	if (argc == 1)
		return (0); 							// no parameters 
	stack_init(&a); 							// initialize stack a
	stack_init(&b); 							// init stack b
	build_stack(&a, &config);					// build stack a
	free_stack(&a);								// free everyting
	free_stack(&b);
	return (0);
}
