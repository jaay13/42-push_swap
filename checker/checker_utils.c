/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:05:56 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 15:52:31 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	read_input(t_stack *a, t_stack *b, t_config *config)
{
	char	*line;

	line = get_next_line(0);									// get input from stdin, eg.: ra, pa, pb
	while (line)
	{
		execute_input_operation(a, b, config, line);			// executes operation command, if no correct input print error
		free(line);
		line = get_next_line(0);
	}
}

void	execute_input_operation(t_stack *a, t_stack *b, t_config *config, char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		sa(a, config);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		sb(b, config);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		ss(a, b, config);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		pa(a, b, config);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		pb(a, b, config);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		ra(a, config);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		rb(b, config);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		rr(a, b, config);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		rra(a, config);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		rrb(b, config);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		rrr(a, b, config);
	else
		checker_error_n_free(a, b, config, line);
}

void	checker_error_n_free(t_stack *a, t_stack *b, t_config *config, char *line)
{
	free(line);
	free_stack(a);
	free_stack(b);
	free_str_array(config->tokens);
	ft_printf_fd(2, "Error\n");
	exit(1);
}
