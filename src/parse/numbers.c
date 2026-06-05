/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:14:27 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/05 20:17:03 by jakoch           ###   ########.fr       */
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
	int count;
	char **tokens;

	i = 0;
	arg_count = argc - start_index;
	if (start_index >= argc) // no numeric args after start_index
		return (NULL);
	if (arg_count == 1 && !argv[start_index][0]) // one numeric argv entry
	{
		tokens = ft_split(argv[start_index], ' ');
		if (!tokens)
			return (NULL);
		count = token_count(tokens);
		if (!validate_nums(tokens, count))
			return (free_str_array(tokens, count), NULL);
		return (tokens);
	}
	if (arg_count > 1) // more than one numberic argv entry
	{
		tokens = malloc((arg_count + 1) * sizeof(char *)); // allocate the char ** array
		if (!tokens)
			return (NULL);
		while (i < arg_count) // do until all args are used up
		{
			tokens[i] = ft_strdup(argv[start_index + i]); // duplicate the argument string into tokens
			if (!tokens[i]) // if one copy fails, free up what was already allocated and return NULL
				return (free_str_array(tokens, i), NULL); 
			i++;
		}
		tokens[arg_count] = NULL; // set last token to NULL
		validate_nums(tokens, i);
		return (tokens);
	}
	return (NULL);		
}