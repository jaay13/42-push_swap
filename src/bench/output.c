/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:01:46 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/11 15:15:33 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

The optional benchmark mode (--bench) must display, after sorting:

◦ The computed disorder (% with two decimals).

◦ The name of the strategy used and its theoretical complexity class.

◦ The total number of operations.

◦ The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
rrr).

◦ Notation: lines prefixed with [bench] represent messages printed by the optional bench-
mark mode (to stderr). The operation stream remains on stdout.

*/

#include "../inc/push_swap.h"

static void print_disorder(t_config *config);


void print_bench(t_config *config)
{
		write(2, "[bench] disorder: ", 18);
		print_disorder(config);
		write(2, "", 19);
		//WIP
}

static void print_disorder(t_config *config)
{
	int percent;
	int	whole;
	int	decimal;

	percent = (int)(config->disorder * 10000.0f + 0.5f);
	whole = percent / 100;
	decimal = percent % 100;
	ft_putnbr_fd(whole, 2);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);
	write(2, "%\n", 2);
}

// TODO: fix config.strategy picker as there is no way of knowing if adaptive way choosen because it gets overwritten
static void print_strategy (t_config *config)
{
	if (config->strategy == SIMPLE)
		write(2, "[bench] strategy: Simple / O(n²)\n", 34);
	else if (config->strategy == MEDIUM)
		write(2, "[bench] strategy: Medium / O(n√n)\n", 34);
	else if (config->strategy == COMPLEX)
		write(2, "[bench] strategy: Complex / O(nlogn)\n", 37);
	else
		write(2, "[bench] strategy: \n", 37);
	
}