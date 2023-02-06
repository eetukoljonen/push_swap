/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:43:44 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/03 15:03:43 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int check, char **argv)
{
	if (check)
		free_string_array(argv);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	ft_atoi_ps(const char *str)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = sign * -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if ((result > 2147483647 && sign == 1)
		|| (result > 2147483648 && sign == -1))
		print_error(0, NULL);
	return (result * sign);
}

void	check_duplicates(char **argv, int row, int check)
{
	int	second;
	int	tmp;

	tmp = row;
	second = tmp + 1;
	while (argv[row])
	{
		while (argv[second])
		{
			if (!ft_strncmp(argv[row], argv[second++], SIZE_MAX))
				print_error(check, argv);
			if (row == second)
				second++;
		}
		row++;
		second = tmp;
	}
}

void	check_digits(char **argv, int row, int check)
{
	int	index;

	if (argv[row][0] == '-')
		index = 1;
	else
		index = 0;
	if (!argv[row][index] || ft_strlen(argv[row]) > 11)
		print_error(check, argv);
	while (argv[row][index])
	{
		if (!ft_isdigit(argv[row][index++]))
			print_error(check, argv);
	}
}

void	check_if_valid(char **argv, int argc)
{
	int	tmp;
	int	row;
	int	check;

	row = 1;
	check = 0;
	if (!argv[1][0])
		exit (0);
	if (argc == 2 && ft_strrchr(argv[1], ' '))
	{
		argv = ft_split(argv[1], ' ');
		row = 0;
		check = 1;
	}
	tmp = row;
	while (argv[row])
	{
		check_digits(argv, row, check);
		row++;
	}	
	check_duplicates(argv, tmp, check);
	if (check)
		free_string_array(argv);
}
