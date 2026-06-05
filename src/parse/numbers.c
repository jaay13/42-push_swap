/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:14:27 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/05 19:27:41 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Make sure ./push_swap 1 2 3 and ./push_swap "1 2 3" behave the same

static void free_str_array(char **tokens, int count)
{
	int i;

	i = 0;
	if (!tokens)
		return ;
	while (i < count)
		free(tokens[i++]);
	free(tokens);
}

char **parse_numbers(int argc, char **argv, int start_index)
{
	int arg_count;
	int i;
	char **tokens;

	i = 0;
	arg_count = argc - start_index;
	if (start_index >= argc) // no numeric args after start_index
		return (NULL);
	if (arg_count == 1) // one numeric argv entry
		return (split(argv[start_index], ' '));
	if (arg_count > 1) // more than one numberic argv entry
	{
		tokens = malloc((arg_count + 1) * sizeof(char *));
		if (!tokens)
			return (NULL);
		while (i < arg_count)
		{
			tokens[i] = ft_strdup(argv[start_index + i]);
			if (!tokens[i])
				return (free_str_array(tokens, i), NULL);
			i++;
		}
		tokens[arg_count] = NULL;
		return (tokens);
	}		
	return (NULL);		
}