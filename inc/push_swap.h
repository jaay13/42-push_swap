/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:53:51 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/15 13:12:11 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>  			// INT_MIN, INT_MAX
# include <stdbool.h> 			// true, false, readability
# include <stdlib.h>  			// malloc, free, exit
# include <unistd.h>  			// write
# include <math.h>				// sqrt

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
	int size;       			// How many nodes are inside
	t_node *top;    			// Pointer to the top of the stack
	t_node *bottom; 			// Pointer to the bottom of the stack
}		t_stack;

typedef struct s_config			// Stores parsing results, strategy choosen, bench counters
{
	int num_start;            	// first argv that is not a flag
	enum e_strategy strategy; 	// sets which strategy is used
	bool strategy_picked;		// to know if a strategy was already chosen, preventing multiple flags 
	bool adaptive;				// to know if the actual flag used was --adaptive / non (default adaptive)
	bool bench;               	// optional bench mode toggle
	char **tokens;				// store the created tokens from parser
	float disorder;				// disorder metric for stack a
	int total_ops;				// keep total operations count for bench
	int pa;						// following keep count for each operation to print in bench
	int pb;
	int rra;
	int rrb;
	int rrr;
	int ra;
	int rb;
	int rr;
	int sa;
	int sb;
	int ss;
}		t_config;

/* ---------------	STACK	--------------- */
void	stack_init(t_stack *stack);
void	build_stack(t_stack *stack, t_config *config);
void	append_node(t_stack *stack, t_node *node);
void	bring_min_to_top_of(t_stack *a, t_config *config);
void 	push_max_chunks_to_a(t_stack *a, t_stack *b, t_config *config);
void	free_stack(t_stack *stack);

/* ---------------	PARSER	--------------- */
void	parse_input(int argc, char **argv, t_config *config);
int		parse_flags(char *arg, t_config *config);
char	**parse_numbers(int argc, char **argv, int start_index);
bool	validate_nums(char **tokens);

/* ---------------	ALGOS --------------- */
void	choose_algo(t_stack *a, t_stack *b, t_config *config);
void	strategy_picker(t_config *config);
void	sort_three(t_stack *a, t_config *config);
void	simple_sort(t_stack *a, t_stack *b, t_config *config);
void	medium_sort(t_stack *a, t_stack *b, t_config *config);
void	complex_sort(t_stack *a, t_stack *b, t_config *config);

/* ---------------	OPERATIONS	--------------- */
void	sa(t_stack *a, t_config *config);
void	sb(t_stack *b, t_config *config);
void	ss(t_stack *a, t_stack *b, t_config *config);
void	pa(t_stack *a, t_stack *b, t_config *config);
void	pb(t_stack *a, t_stack *b, t_config *config);
void	ra(t_stack *a, t_config *config);
void	rb(t_stack *b, t_config *config);
void	rr(t_stack *a, t_stack *b, t_config *config);
void	rra(t_stack *a, t_config *config);
void	rrb(t_stack *b, t_config *config);
void	rrr(t_stack *a, t_stack *b, t_config *config);

/* ---------------	UTILS	--------------- */
void	error_n_free(char **tokens, int *nums);
void	free_str_array(char **tokens);
long	ft_atol(const char *str);
int		syntax_error(char *token);
int 	repetition_error(long nbr, int *nums, int i);
int		*copy_stack_into_array(t_stack *a);
void	sort_array(int *copied_array, int stack_size);
void	turn_stack_value_into_rank(t_stack *a, int *sorted_array);
void	push_chunk_value_to_b(t_stack *a, t_stack *b, t_config *config, int chunk_start, int chunk_end, int *pushed);
void	update_chunk(int *chunk_start, int *chunk_end, int chunk_size, int a_size);

/* ---------------	BENCH	--------------- */
void	compute_disorder(t_stack *a, t_config *config);
void 	print_bench(t_config *config);

#endif
