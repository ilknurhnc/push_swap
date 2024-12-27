/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihancer <ihancer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:36:52 by ihancer           #+#    #+#             */
/*   Updated: 2024/12/27 16:51:54 by ihancer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **node)
{
	int	temp;

	if (ft_lstsize(*node) > 1)
	{
		temp = (*node)->next->content;
		(*node)->next->content = (*node)->content;
		(*node)->content = temp;
	}
	return ;
}

void	sa(t_stack **node_a)
{
	swap(node_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **node_b)
{
	swap(node_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **node_a, t_stack **node_b)
{
	swap(node_a);
	swap(node_b);
	write(1, "ss\n", 3);
}
