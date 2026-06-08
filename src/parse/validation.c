/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:35:00 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/08 12:35:54 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check the created char ** for any invalid formats, INT_MAX / INT_MIN, RANGE, DUPES
#include "../inc/push_swap.h"

int token_count(char **tokens) //TODO
{
	int count;

	count = 0;

	return (count);
}

bool	validate_nums(char **tokens)
{
	long	nbr;
	int		i;
	int		*nums;

	i = token_count(tokens);
	nums = malloc(sizeof(int) * i);
	i = 0;
	while (tokens[i])
	{
		if (syntax_error(tokens[i])) // check syntax
			return (error_n_free(tokens, nums), false);
		nbr = ft_atol(tokens[i]);           // converto to long
		if (nbr > INT_MAX || nbr < INT_MIN) // check range
			return (error_n_free(tokens, nums), false);
		if (repetition_error(nbr, nums, i)) // check dupes against already accepted nums
			return (error_n_free(tokens, nums), false);
		nums[i] = (int)nbr; // store accepted num in nums
		i++;
	}
	free(nums);
	return (true);
}
