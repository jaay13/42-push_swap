/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:13:14 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/10 12:48:35 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// check for argv flags such as --simple, --medium, --complex, --adaptive, --bench

int	parse_flags(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--simple", 9) == 0 && arg[8] == '\0')	// compare the flag to "--simple" if they match strncmp returns 0, 9 characers because 8 + \0
	{
		config->strategy = SIMPLE;
		config->strategy_picked = true;
	}
	else if (ft_strncmp(arg, "--medium", 9) == 0 && arg[8] == '\0') // && arg[8] checks also if the last character is '\0' and so not something like "--mediums" will be accepted
	{
		config->strategy = MEDIUM;
		config->strategy_picked = true;
	}
	else if (ft_strncmp(arg, "--complex", 10) == 0 && arg[9] == '\0')
	{
		config->strategy = COMPLEX;
		config->strategy_picked = true;
	}
	else if (ft_strncmp(arg, "--adaptive", 11) == 0 && arg[10] == '\0')
	{
		config->strategy_picked = true;
	}
	else if (ft_strncmp(arg, "--bench", 8) == 0 && arg[7] == '\0')
	{
		config->bench = true;
		config->strategy_picked = true;
	}
	return (config->strategy_picked);
}
