/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:58:56 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/04 15:05:50 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;

	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;

}						t_stack_node;

// Handle errors

// stack init

// nodes init

// stack utils

// commands

//algorithms

#endif