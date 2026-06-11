/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:01:46 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/11 17:23:59 by jakoch           ###   ########.fr       */
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
static void print_strategy (t_config *config);


void print_bench(t_config *config)
{
		print_disorder(config);
		print_strategy(config);
		//WIP
}

static void print_disorder(t_config *config)
{
	int percent;
	int	whole;
	int	decimal;

	percent = (int)(config->disorder * 10000.0f + 0.5f);					// config->disorder 0-1, e.g. 0.1666 * 10000.0f = 1666.66.. + 0.5f = 1667.1.. becomes 1667 because of int
	whole = percent / 100;													// 1667 / 100 = 16.67 (int: 16)
	decimal = percent % 100;												// 1667 % 100 = 67 (whole number already)
	write(2, "[bench] disorder: ", 18);
	ft_putnbr_fd(whole, 2);													// writes "16" to stderr
	write(2, ".", 1);														// "16." <- .
	if (decimal < 10)														// all decimals under 10 get shifted one, so its 40.07% not 40.7%, or not 40.0% but 40.00%
		write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);												// "16.67" <- decimal = 67
	write(2, "%\n", 2);														// "16.67\n" <- \n 
}

static void print_strategy (t_config *config)
{
	if (config->strategy == SIMPLE && config->adaptive == true)				// check if adaptive choose the simple strategy
		write(2, "[bench] strategy: Adaptive / O(n²)\n", 35);
	else if (config->strategy == MEDIUM && config->adaptive == true) 		
		write(2, "[bench] strategy: Adaptive / O(n√n)\n", 37);
	else if (config->strategy == COMPLEX && config->adaptive == true)
		write(2, "[bench] strategy: Adaptive / O(nlogn)\n", 38);
	else if (config->strategy == SIMPLE)
		write(2, "[bench] strategy: Simple / O(n²)\n", 34);
	else if (config->strategy == MEDIUM)
		write(2, "[bench] strategy: Medium / O(n√n)\n", 35);
	else if (config->strategy == COMPLEX)
		write(2, "[bench] strategy: Complex / O(nlogn)\n", 37);
}