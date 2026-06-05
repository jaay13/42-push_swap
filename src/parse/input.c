/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:28:46 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/05 20:18:11 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void config_init(t_config *config)
{
	config->num_start = 1;
	config->strategy = ADAPTIVE; // set adaptive as default strat
	config->bench = false;
}

void	parse_input(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	config_init(config);
	while (i < argc) // Loop until argv arent flags anymore
	{
		if (parse_flags(argv[i], config)) // check wether argument is a flag and store it
			i++;
		else
			break ;
	}
	config->num_start = i;
	// now parse number nows at what argv index the numerics start
	parse_numbers(argc, argv, config->num_start);
}
