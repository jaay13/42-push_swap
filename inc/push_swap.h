/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:53:51 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/11 17:29:55 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>  			// INT_MIN, INT_MAX
# include <stdbool.h> 			// true, false, readability
# include <stdlib.h>  			// malloc, free, exit
# include <unistd.h>  			// write

enum	e_strategy
{
	ADAPTIVE = 0,
	SIMPLE = 1,
	MEDIUM = 2,
	COMPLEX = 3
};

typedef struct s_node 			// Single Node
{
	int value;         			// Value of a node, e.g.: 42
	struct s_node *next; 		// Pointer to the next node
	struct s_node *prev; 		// Pointer to previous node
}		t_node;

typedef struct s_stack 			// A stack (a or b) made of linked nodes
{
	char name;      			// a or b
	int size;       			// How many nodes are inside
	t_node *top;    			// Pointer to the top of the stack
	t_node *bottom; 			// Pointer to the bottom of the stack
}		t_stack;

typedef struct s_config
{
	int num_start;            	// first argv that is not a flag
	enum e_strategy strategy; 	// sets which strategy is used
	bool adaptive;				// to know if the actual flag used was --adaptive / non (default adaptive)
	bool bench;               	// optional bench mode toggle
	char **tokens;				// store the created tokens from parser
	int count;					// how many were created
	float disorder;				// disorder metric for stack a
}		t_config;

/* ---------------	STACK	--------------- */
void	stack_init(t_stack *stack, char name);
void	build_stack(t_stack *stack, t_config *config);
void	append_node(t_stack *stack, t_node *node);
void	bring_min_to_top_of(t_stack *a);
void	free_stack(t_stack *stack);

/* ---------------	PARSER	--------------- */
void	parse_input(int argc, char **argv, t_config *config);
int		parse_flags(char *arg, t_config *config);
char	**parse_numbers(int argc, char **argv, int start_index);
bool	validate_nums(char **tokens);

/* ---------------	ALGOS --------------- */
void	choose_algo(t_stack *a, t_stack *b, t_config *config);
void	strategy_picker(t_config *config);
void	tiny_sort(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	simple_sort(t_stack *a, t_stack *b);
void	medium_sort(t_stack *a, t_stack *b);
void	complex_sort(t_stack *a, t_stack *b);

/* ---------------	OPERATIONS	--------------- */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* ---------------	UTILS	--------------- */
void	error_n_free(char **tokens, int *nums);
void	free_str_array(char **tokens);
long	ft_atol(const char *str);
int		syntax_error(char *token);
int 	repetition_error(long nbr, int *nums, int i);

/* ---------------	BENCH	--------------- */
void	compute_disorder(t_stack *a, t_config *config);
void 	print_bench(t_config *config);


#endif
