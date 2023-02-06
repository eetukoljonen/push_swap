/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:03:20 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/03 15:04:06 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **head, t_stack *new)
{
	if (*head == NULL)
	{
		*head = new;
		(*head)->next = NULL;
		(*head)->previous = NULL;
		return ;
	}
	if ((*head)->next == new)
	{
		(*head)->next = new->next;
		(*head)->next->previous = *head;
	}
	new->next = *head;
	(*head)->previous = new;
	*head = new;
	(*head)->previous = NULL;
}

void	ft_lstadd_back(t_stack **head, t_stack *new)
{
	t_stack	*tmp;

	if (*head == NULL)
		*head = new;
	tmp = ft_lst_last(*head);
	tmp->next = new;
	new->next = NULL;
	new->previous = tmp;
}

t_stack	*ft_lst_last(t_stack *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

int	ft_lst_size(t_stack *head)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
