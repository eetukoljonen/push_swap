/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:32:17 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/06 14:04:01 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**head_a;

	head_a = NULL;
	if (argc == 1)
		return (0);
	check_if_valid(argv, argc);
	if (argc == 2 && ft_strrchr(argv[1], ' '))
	{
		argv = ft_split(argv[1], ' ');
		head_a = make_stack(argv, 0);
		free_string_array(argv);
	}
	else
		head_a = make_stack(argv, 1);
	sort_stack(head_a);
	free_list(head_a);
	return (0);
}
