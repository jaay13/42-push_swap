/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:28:46 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/05 17:43:16 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	parse_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i]) // Loop until argv arent flags anymore
	{
		if (parse_flags(argc, argv[i])) // check wether argument is a flag and store it
			i++;
		else
			break ;
	}
	// now parse number nows at what argv index the numerics start
	parse_numbers(argc, argv, i);
}
