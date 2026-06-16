/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:01:46 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/16 14:53:06 by jakoch           ###   ########.fr       */
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
static void print_total_ops(t_config *config);
static void print_individual_ops(t_config *config);

void print_bench(t_config *config)
{
		print_disorder(config);
		print_strategy(config);
		print_total_ops(config);
		print_individual_ops(config);
}

static void print_disorder(t_config *config)
{
	int percent;
	int	whole;
	int	decimal;

	percent = (int)(config->disorder * 10000.0f + 0.5f);					// config->disorder 0-1, e.g. 0.1666 * 10000.0f = 1666.66.. + 0.5f = 1667.1.. becomes 1667 because of int
	whole = percent / 100;													// 1667 / 100 = 16.67 (int: 16)
	decimal = percent % 100;												// 1667 % 100 = 67 (whole number already)
	if (decimal < 10)
		ft_printf_fd(2, "[bench] disorder: %d.0%d%%\n", whole, decimal);	// all decimals under 10 get shifted one, so its 40.07% not 40.7%, or not 40.0% but 40.00%
	else																	
		ft_printf_fd(2, "[bench] disorder: %d.%d%%\n", whole, decimal);		// "16.67\n" <- whole.decimal% = 16.67%+\n
}

static void print_strategy (t_config *config)
{
	if (config->strategy == SIMPLE && config->adaptive == true)				// check if adaptive choose the simple strategy
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(n²)\n");
	else if (config->strategy == MEDIUM && config->adaptive == true) 		
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(n√n)\n");
	else if (config->strategy == COMPLEX && config->adaptive == true)
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(nlogn)\n");
	else if (config->strategy == SIMPLE)
		ft_printf_fd(2, "[bench] strategy: Simple / O(n²)\n");
	else if (config->strategy == MEDIUM)
		ft_printf_fd(2, "[bench] strategy: Medium / O(n√n)\n");
	else if (config->strategy == COMPLEX)
		ft_printf_fd(2, "[bench] strategy: Complex / O(nlogn)\n");
}

static void print_total_ops(t_config *config)
{
	ft_printf_fd(2, "[bench] total ops: %d\n", config->total_ops);
}

static void print_individual_ops(t_config *config)
{
	ft_printf_fd(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", config->sa, config->sb, config->ss, config->pa, config->pb);
	ft_printf_fd(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", config->ra, config->rb, config->rr, config->rra, config->rrb, config->rrr);
}