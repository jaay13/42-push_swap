/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:53:51 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/05 15:35:08 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>  // INT_MIN, INT_MAX
# include <stdbool.h> // true, false, readability
# include <stdlib.h>  // malloc, free, exit
# include <unistd.h>  // write

typedef struct s_node // Single Node
{
	int value;           // Value of a node, e.g.: 42
	struct s_node *next; // Pointer to the next node
	struct s_node *prev; // Pointer to previous node
}	t_node;

typedef struct s_stack // Our stacks a and b, collection of nodes
{
	char name;      // a or b
	int size;       // How many nodes are inside
	t_node *top;    // Pointer to the top of the stack
	t_node *bottom; // Pointer to the bottom of the stack
}	t_stack;

/* ---------------	STACK	--------------- */

/* ---------------	PARSER	--------------- */

/* ---------------	ALGOS --------------- */

/* ---------------	OPERATIONS	--------------- */

/* ---------------	UTILS	--------------- */

/* ---------------	BENCH	--------------- */


#endif