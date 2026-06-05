/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:35:00 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/05 20:17:20 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check the created char ** for any invalid formats, INT_MAX / INT_MIN, RANGE, DUPES
#include "../inc/push_swap.h"

int	validate_nums(char **tokens, int count)
{
	long	nbr;
	int		i;
	int *nums;
	int num_used;

	i = 0;
	nums = malloc(sizeof(int) * count);
	while (tokens[i])
	{
		if (syntax_error(tokens[i])) // check syntax
			error_n_free(tokens, i);
		nbr = ft_atol(tokens[i]); // converto to long
		if (nbr > INT_MAX || nbr < INT_MIN) // check range
			error_n_free(tokens, i);
		if (repetition_error(nbr, nums, i)) // check dupes against already accepted nums
		{
			error_n_free(tokens, i);
			nums[i] = (int)nbr; // store accepted num in nums
		}
		i++;
	}
}

static long	ft_atol(const char *str)
{
	int		i;
	int		symbol;
	long	result;

	i = 0;
	symbol = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			symbol = -symbol;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * symbol);
}
