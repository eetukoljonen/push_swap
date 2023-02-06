/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:00:27 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/03 15:04:02 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_node(int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (new_node = NULL);
	new_node->data = number;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

t_stack	**make_stack(char **argv, int row)
{
	t_stack	**head;

	head = (t_stack **)malloc(sizeof(t_stack *));
	if (!head)
		return (head = NULL);
	*head = NULL;
	while (argv[row])
		ft_lstadd_back(head, create_new_node(ft_atoi_ps(argv[row++])));
	return (head);
}
