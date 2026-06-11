/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:13:14 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/11 13:29:54 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// check for argv flags such as --simple, --medium, --complex, --adaptive, --bench

int	parse_flags(char *arg, t_config *config)
{
	static int strategy_set = 0;

	if (ft_strncmp(arg, "--simple", 9) == 0 && arg[8] == '\0')
	{
		if (strategy_set)
			return (0);
		config->strategy = SIMPLE;
		strategy_set = 1;
		return (1);
	}
	if (ft_strncmp(arg, "--medium", 9) == 0 && arg[8] == '\0')
	{
		if (strategy_set)
			return (0);
		config->strategy = MEDIUM;
		strategy_set = 1;
		return (1);
	}
	if (ft_strncmp(arg, "--complex", 10) == 0 && arg[9] == '\0')
	{
		if (strategy_set)
			return (0);
		config->strategy = COMPLEX;
		strategy_set = 1;
		return (1);
	}
	if (ft_strncmp(arg, "--adaptive", 11) == 0 && arg[10] == '\0')
	{
		if (strategy_set)
			return (0);
		strategy_set = 1;
		return (1);
	}
	if (ft_strncmp(arg, "--bench", 8) == 0 && arg[7] == '\0')
	{
		config->bench = true;
		return (1);
	}
	return (0);
}
