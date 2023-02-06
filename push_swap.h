/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:32:35 by ekoljone          #+#    #+#             */
/*   Updated: 2023/02/06 14:03:59 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*previous;
}				t_stack;

/* errors */
void	check_if_valid(char **argv, int argc);
void	check_digits(char **argv, int row, int check);
void	check_duplicates(char **argv, int row, int check);
int		ft_atoi_ps(const char *str);
void	print_error(int check, char **argv);
/* free */
void	free_string_array(char **args);
void	free_all_nodes(t_stack **head);
void	free_list(t_stack **head);
/* list_utils */
void	ft_lstadd_front(t_stack **head, t_stack *new);
void	ft_lstadd_back(t_stack **head, t_stack *new);
t_stack	*ft_lst_last(t_stack *head);
int		ft_lst_size(t_stack *head);
/* make_stack */
t_stack	*create_new_node(int number);
t_stack	**make_stack(char **argv, int row);
/* operations */
void	swap(t_stack **head, char a_b);
void	rotate(t_stack **head, char a_b);
void	reverse_rotate(t_stack **head, char a_b);
void	push(t_stack **push_to_this, t_stack **push_this, char a_b);
/* smart_rotate */
int		check_head(t_stack **head, int this, int range);
int		check_tail(t_stack **head, int this, int range);
void	smart_rotate(t_stack **head, int this, int range, char a_b);
/* sort_utils */
int		check_if_sorted(t_stack **head_a, t_stack **head_b);
int		check_if_pushed(t_stack **head, int range_start, int range_end);
int		*get_chunks(t_stack **head);
void	push_in_order(t_stack **head_a, t_stack **head_b);
/* utils */
int		return_index(t_stack **head, int lst_size);
int		return_smallest(t_stack **head);
int		return_largest(t_stack **head);
/* sorter */
void	big_sort(t_stack **head_a);
void	sort_three(t_stack **head_a);
void	sorter(t_stack **head_a);
void	sort_stack(t_stack **head_a);

#endif