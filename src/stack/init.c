/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakoch <jakoch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:59:18 by jakoch            #+#    #+#             */
/*   Updated: 2026/06/05 17:09:11 by jakoch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_init(t_stack *ptr, char name)
{
	if (!ptr)
		return ;
	ptr->name = name;
	ptr->size = 0;
	ptr->top = NULL;
	ptr->bottom = NULL;
}
