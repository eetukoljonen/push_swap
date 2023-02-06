/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:51:37 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/03 15:09:54 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_head(t_stack **head, int this, int range)
{
	t_stack	*tmp;
	int		iterations;
	int		check;

	tmp = *head;
	iterations = 0;
	check = tmp->data;
	while (tmp)
	{
		if (check >= this && check <= range)
			return (iterations);
		tmp = tmp->next;
		if (tmp)
			check = tmp->data;
		iterations++;
	}
	return (0);
}

int	check_tail(t_stack **head, int this, int range)
{
	t_stack	*tmp;
	int		iterations;
	int		check;

	tmp = ft_lst_last(*head);
	iterations = 1;
	check = tmp->data;
	while (tmp)
	{
		if (check >= this && check <= range)
			return (iterations);
		tmp = tmp->previous;
		if (tmp)
			check = tmp->data;
		iterations++;
	}
	return (0);
}

void	smart_rotate(t_stack **head, int this, int range, char a_b)
{
	if (!(*head) || ft_lst_size(*head) < 2)
		return ;
	if (check_head(head, this, range) < check_tail(head, this, range))
		rotate(head, a_b);
	else
		reverse_rotate(head, a_b);
}
