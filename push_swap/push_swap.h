/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilknurhancer <ilknurhancer@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:32:48 by ilknurhance       #+#    #+#             */
/*   Updated: 2024/12/27 00:40:56 by ilknurhance      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}					t_stack;

// stack-op
void				sa(t_stack **node_a);
void				sb(t_stack **node_b);
void				ss(t_stack **node_a, t_stack **node_b);

void				ra(t_stack **node_a);
void				rb(t_stack **node_b);
void				rr(t_stack **node_a, t_stack **node_b);

void				pa(t_stack **node_a, t_stack **node_b);
void				pb(t_stack **node_a, t_stack **node_b);

void				rra(t_stack **node_a);
void				rrb(t_stack **node_b);
void				rrr(t_stack **node_a, t_stack **node_b);

// stack-index
void				add_stack(t_stack **stack, int argc, char *argv[]);
void				fill_index(t_stack **stack);
void				add_index(t_stack **stack);
void				free_stack(t_stack **stack);

// argv
void	            error(void);
void				check_arg(int argc, char *argv[]);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
int					ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
int					ft_isdigit(int c);
void	            free_str(char **str);


// sort
int					is_sorted(t_stack **stack);
void				main_sort(t_stack **stack_a, t_stack **stack_b);
void				position(t_stack **stack_a, t_stack **stack_b);
t_stack 			*min_node(t_stack **stack);
int	get_max_bits(t_stack **stack);


// list
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);

#endif