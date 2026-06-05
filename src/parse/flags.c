/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:13:14 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/05 18:36:37 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// check for argv flags such as --simple, --medium, --complex, --adaptive, --bench

int	parse_flags(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		// compare the flag to "--simple" if they match strncmp returns 0, 9 characers because 8 + \0
	{
		config->strategy = SIMPLE;
		return (1);
	}
	else if (ft_strncmp(arg, "--medium", 9) == 0)
	{
		config->strategy = MEDIUM;
		return (1);
	}
	else if (ft_strncmp(arg, "--complex", 10) == 0)
	{
		config->strategy = COMPLEX;
		return (1);
	}
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
	{
		config->strategy = ADAPTIVE;
		return (1);
	}
	else if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		config->bench = true;
		return (1);
	}
	else // not a flag so condition is false
		return (0);
}
