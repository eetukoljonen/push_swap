/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:54:59 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/03 15:03:36 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;
	t_stack	*first;

	if (*head_b)
		return (0);
	if (ft_lst_size(*head_a) < 1)
		return (1);
	tmp = *head_a;
	first = *head_a;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (first->data > tmp->data)
			return (0);
		first = first->next;
		tmp = tmp->next;
	}
	return (1);
}

int	check_if_pushed(t_stack **head, int range_start, int range_end)
{
	t_stack	*tmp;
	int		check;

	tmp = *head;
	check = tmp->data;
	while (tmp)
	{
		if (check >= range_start && check <= range_end)
			return (0);
		tmp = tmp->next;
		if (tmp)
			check = tmp->data;
	}
	return (1);
}

int	*get_chunks(t_stack **head)
{
	int	*chunks;
	int	size;
	int	index;
	int	division;

	if (ft_lst_size(*head) <= 50)
		size = 2;
	else if (ft_lst_size(*head) <= 200)
		size = 6;
	else
		size = 11;
	chunks = (int *)malloc(sizeof(int) * size);
	if (!chunks)
		return (0);
	division = ft_lst_size(*head) / size;
	index = ft_lst_size(*head) - 1;
	while (size >= 0)
	{
		chunks[size--] = return_index(head, index);
		if (size == 0)
			index = 0;
		else
			index -= division;
	}
	return (chunks);
}

void	push_in_order(t_stack **head_a, t_stack **head_b)
{
	while (*head_b)
	{
		if ((*head_b)->data == return_largest(head_b))
			push(head_a, head_b, 'a');
		else
			smart_rotate(head_b, return_largest(head_b),
				return_largest(head_b), 'b');
	}
}
