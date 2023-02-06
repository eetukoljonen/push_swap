/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:46:49 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/03 15:03:57 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head, char a_b)
{
	t_stack	*tmp;

	if (ft_lst_size(*head) < 2)
		return ;
	tmp = *head;
	tmp = tmp->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
	if (a_b == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	rotate(t_stack **head, char a_b)
{
	t_stack	*last;

	last = ft_lst_last(*head);
	if (ft_lst_size(*head) < 2)
		return ;
	last->next = *head;
	(*head)->previous = last;
	*head = (*head)->next;
	(*head)->previous = NULL;
	last = last->next;
	last->next = NULL;
	if (a_b == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	reverse_rotate(t_stack **head, char a_b)
{
	t_stack	*last;
	t_stack	*second_last;

	last = ft_lst_last(*head);
	(*head)->previous = last;
	second_last = *head;
	if (ft_lst_size(*head) < 2)
		return ;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = *head;
	*head = last;
	(*head)->previous = NULL;
	if (a_b == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	push(t_stack **push_to_this, t_stack **push_this, char a_b)
{
	t_stack	*tmp;

	tmp = *push_this;
	if (!tmp)
		return ;
	*push_this = (*push_this)->next;
	ft_lstadd_front(push_to_this, tmp);
	if (a_b == 'a')
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}
