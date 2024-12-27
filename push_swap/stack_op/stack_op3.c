/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihancer <ihancer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:06:44 by ihancer           #+#    #+#             */
/*   Updated: 2024/12/27 16:50:55 by ihancer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrotate(t_stack **node)
{
	t_stack	*end;
	t_stack	*second_end;

	if (ft_lstsize(*node) > 1)
	{
		end = ft_lstlast(*node);
		second_end = *node;
		while (second_end->next != end)
			second_end = second_end->next;
		second_end->next = NULL;
		end->next = *node;
		*node = end;
	}
	return ;
}

void	rra(t_stack **node_a)
{
	rrotate(node_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **node_b)
{
	rrotate(node_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **node_a, t_stack **node_b)
{
	rrotate(node_a);
	rrotate(node_b);
	write(1, "rrr\n", 4);
}
