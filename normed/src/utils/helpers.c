/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:47:26 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/18 19:50:46 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atol(const char *str)
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

int	ft_int_sqrt(int number)
{
	int	root;

	if (number == 0 || number < 0)
		return (0);
	if (number == 1)
		return (1);
	root = 0;
	while (root + 1 <= number / (root + 1))
		root++;
	return (root);
}
