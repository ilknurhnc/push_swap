/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilknurhancer <ilknurhancer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:16:57 by ihancer           #+#    #+#             */
/*   Updated: 2024/12/26 08:56:34 by ilknurhance      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **node)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*node) > 2)
	{
		first = *node;
		last = ft_lstlast(*node);
		*node = (*node)->next;
		last->next = first;
		first->next = NULL;
	}
	return ;
}

void	ra(t_stack **node_a)
{
	rotate(node_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **node_b)
{
	rotate(node_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **node_a, t_stack **node_b)
{
	rotate(node_a);
	rotate(node_b);
	write(1, "rr\n", 3);
}