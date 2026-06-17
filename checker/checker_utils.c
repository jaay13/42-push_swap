/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:05:56 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/17 14:52:06 by jakoch           ###   ########.fr       */
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
