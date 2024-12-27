/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihancer <ihancer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:49:27 by ihancer           #+#    #+#             */
/*   Updated: 2024/12/27 16:49:32 by ihancer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a)
{
	t_stack	*node;

	node = *stack_a;
	if (is_sorted(stack_a))
		return ;
	if (min_node(stack_a) == ft_lstlast(*stack_a))
	{
		if (node->index > node->next->index)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
			rra(stack_a);
	}
	else if (node->next->index > node->index)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (ft_lstlast(*stack_a)->index > node->index)
		sa(stack_a);
	else
		ra(stack_a);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a))
		return ;
	position(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	position(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;
	t_stack	*node;

	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			node = *stack_a;
			if (((node->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

void	main_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2)
		return ;
	if (is_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_3(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
