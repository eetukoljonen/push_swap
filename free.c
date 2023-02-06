/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:48:54 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/03 15:04:05 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_string_array(char **args)
{
	int	index;

	index = 0;
	while (args[index])
		index++;
	while (index >= 0)
		free(args[index--]);
	free(args);
}

void	free_all_nodes(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (*head)
	{
		*head = (*head)->next;
		free(tmp);
		tmp = *head;
	}
}

void	free_list(t_stack **head)
{
	if (head)
	{
		free_all_nodes(head);
		free(head);
	}
}
