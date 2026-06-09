/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:59:18 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/09 16:51:21 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_init(t_stack *stack, char name)
{
	if (!stack)
		return ;
	stack->name = name;
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

void	build_stack(t_stack *stack, t_config *config)
{
	t_node *new_node;
	int i;
	int nbr;

	i = 0;
	while (config->tokens[i])
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		nbr = ft_atoi(config->tokens[i]);
		new_node->value = nbr;
		append_node(stack, new_node);
		i++;
		stack->size++;
	}
	free(new_node);
}
