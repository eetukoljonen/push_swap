/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:53:20 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/03 15:03:44 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **head_a)
{
	int		*chunks;
	int		range;
	t_stack	**head_b;

	head_b = (t_stack **)malloc(sizeof(t_stack *));
	*head_b = NULL;
	if (!head_b)
		return ;
	chunks = get_chunks(head_a);
	range = 1;
	while (!check_if_sorted(head_a, head_b))
	{
		if ((*head_a)->data <= chunks[range])
			push(head_b, head_a, 'b');
		else
			smart_rotate(head_a, (chunks[0]), chunks[range], 'a');
		if (!(*head_a))
			push_in_order(head_a, head_b);
		else if (check_if_pushed(head_a, chunks[0], chunks[range]))
			range++;
	}
	free_list(head_b);
	free(chunks);
}

void	sort_three(t_stack **head_a)
{
	if ((*head_a)->data == return_largest(head_a))
		rotate(head_a, 'a');
	else if ((*head_a)->next->data == return_largest(head_a))
		reverse_rotate(head_a, 'a');
	if ((*head_a)->data > (*head_a)->next->data)
		swap(head_a, 'a');
}

void	sorter(t_stack **head_a)
{
	t_stack	**head_b;

	head_b = (t_stack **)malloc(sizeof(t_stack *));
	*head_b = NULL;
	if (!head_b)
		return ;
	while (ft_lst_size(*head_a) != 3)
	{
		while ((*head_a)->data != return_smallest(head_a))
			smart_rotate(head_a, return_smallest(head_a),
				return_smallest(head_a), 'a');
		if (check_if_sorted(head_a, head_b))
		{
			free_list(head_b);
			return ;
		}
		push(head_b, head_a, 'b');
	}
	sort_three(head_a);
	while (*head_b)
		push(head_a, head_b, 'a');
	free_list(head_b);
}

void	sort_stack(t_stack **head_a)
{
	t_stack	*tmp;

	tmp = NULL;
	if (check_if_sorted(head_a, &tmp))
		return ;
	if (ft_lst_size(*head_a) == 3)
		sort_three(head_a);
	else if (ft_lst_size(*head_a) <= 15)
		sorter(head_a);
	else
		big_sort(head_a);
}
