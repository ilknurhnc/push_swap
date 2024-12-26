
#include "push_swap.h"
#include <stdio.h>


static void ft_print(t_stack **a)
{
    t_stack *temp = *a;
    while(temp!= NULL)
    {
        printf("%d\n", temp->index);
        temp = temp->next;
    }
}


int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return 0;
	check_arg(argc, argv);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	add_stack(stack_a, argc, argv);
   
	add_index(stack_a);
  
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	ft_print(stack_a);
	main_sort(stack_a, stack_b);
	ft_print(stack_a);
    return (0);
}