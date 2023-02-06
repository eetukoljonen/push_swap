/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:57:51 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/02 19:56:19 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_index(t_stack **head, int lst_size)
{
	t_stack	*tmp;
	t_stack	*first;
	int		counter;

	counter = 0;
	tmp = *head;
	if (!tmp)
		return (0);
	first = *head;
	while (tmp)
	{
		if (first->data > tmp->data)
			counter++;
		tmp = tmp->next;
		if (!tmp)
		{
			if (counter == lst_size)
				return (first->data);
			tmp = *head;
			first = first->next;
			counter = 0;
		}
	}
	return (0);
}

int	return_smallest(t_stack **head)
{
	t_stack	*tmp;
	int		smallest;

	tmp = *head;
	if (!tmp)
		return (0);
	smallest = tmp->data;
	while (tmp)
	{
		if (smallest > tmp->data)
			smallest = tmp->data;
		tmp = tmp->next;
	}
	return (smallest);
}

int	return_largest(t_stack **head)
{
	t_stack	*tmp;
	int		largest;

	tmp = *head;
	if (!tmp)
		return (0);
	largest = tmp->data;
	while (tmp)
	{
		if (largest < tmp->data)
			largest = tmp->data;
		tmp = tmp->next;
	}
	return (largest);
}
