/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_av_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihancer <ihancer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:16:13 by ihancer           #+#    #+#             */
/*   Updated: 2024/12/27 17:32:04 by ihancer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

static int	num_control(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	same_control(int num, char *str[], int index)
{
	index++;
	while (str[index])
	{
		if (ft_atoi(str[index]) == num)
			return (1);
		index++;
	}
	return (0);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	check_arg(int argc, char *argv[])
{
	int		i;
	long	num;
	char	**str;

	i = 0;
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
		str = argv;
	while (str[++i])
	{
		num = ft_atoi(str[i]);
		if (num < -2147483648 || num > 2147483647)
			error();
		if (!num_control(str[i]))
			error();
		if (same_control(num, str, i))
			error();
	}
	if (argc == 2)
		free_str(str);
}
