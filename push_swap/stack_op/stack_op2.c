/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihancer <ihancer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:59:17 by ihancer           #+#    #+#             */
/*   Updated: 2024/12/27 16:54:37 by ihancer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **node_a, t_stack **node_b)
{
	t_stack	*add;

	if (*node_b != NULL)
	{
		add = *node_b;
		*node_b = (*node_b)->next;
		add->next = *node_a;
		*node_a = add;
		write(1, "pa\n", 3);
	}
	return ;
}

void	pb(t_stack **node_a, t_stack **node_b)
{
	t_stack		*add;

	if (*node_a != NULL)
	{
		add = *node_a;
		*node_a = (*node_a)->next;
		add->next = *node_b;
		*node_b = add;
		write(1, "pb\n", 3);
	}
	return ;
}
