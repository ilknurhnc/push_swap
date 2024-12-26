/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilknurhancer <ilknurhancer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:17:40 by ihancer           #+#    #+#             */
/*   Updated: 2024/12/26 16:40:56 by ilknurhance      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_stack(t_stack **stack, int argc, char *argv[])
{
	t_stack	*node;
	char	**str;
	int		i;

    node = *stack;
	i = 0;
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		str = argv;
	}
	while (str[i])
	{
		int value = ft_atoi(str[i]);
        node = ft_lstnew(value);
        if(!node)
            error();
		ft_lstadd_back(stack, node);
		i++;
	}
    if (argc == 2)
        free_str(str);
}

void	fill_index(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node)
	{
		node->index = -1;
		node = node->next;
	}
}

t_stack	*get_min(t_stack **stack)
{
	t_stack	*min;
	t_stack	*node;
	int		control;

	node = *stack;
    min = NULL;
	control = 0;
	if (node)
	{
		while (node)
		{
			if (node->index == -1 && (!control || node->content < min->content))
			{
				min = node;
				control = 1;
			}
			node = node->next;
		}
	}
	return (min);
}

void add_index(t_stack **stack)
{
    t_stack *node;
    int index;

    index = 0;
    fill_index(stack);
    node = get_min(stack);  
    while (node)
    {
        node->index = index++;
        node = get_min(stack); 
    }
}

void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	node = *stack;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	free(stack);
}