/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:28:46 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/09 15:29:53 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void config_init(t_config *config)
{
	config->num_start = 1;
	config->strategy = ADAPTIVE; 										// set adaptive as default strat
	config->bench = false;
	config->tokens = NULL;
	config->count = 0;
}

void	parse_input(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	config_init(config);
	while (i < argc) 													// Loop until argv arguments are numeric
	{
		if (parse_flags(argv[i], config)) 								// check wether argument is a flag and store it
			i++;
		else
			break ;
	}
	config->num_start = i; 												// set numeric start index
	config->tokens = parse_numbers(argc, argv, config->num_start);		// stores **tokens from parse_numbers
	if (!config->tokens) 												// Checks parse_numbers and handles error in case it returns NULL on error
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;																// reset i as it is now used as a counter
	while (config->tokens[i])											// count the amount of tokens created
		i++;
	config->count = i;
}
