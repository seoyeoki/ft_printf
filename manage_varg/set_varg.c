/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_varg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 01:42:11 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/17 04:57:15 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_varg.h"

t_parse_set	***vlist_init(size_t vlist_size) // util로 이동하기
{
	t_parse_set	***vlist;

	vlist = (t_parse_set ***)ft_calloc(vlist_size, sizeof(t_parse_set **));
	return (vlist);
}

void	insert_vlist(t_parse_set *set, t_parse_set ***vlist, size_t pos, size_t *s)
{
	size_t		num;
	t_parse_set	**temp_ptr;

	if (pos == 0)
		return;
	
	pos--;
	if (pos >= *s)
		resize_vlist(&vlist, s);
	num = varg_num(vlist[pos]);
	temp_ptr = (t_parse_set **)ft_calloc((num + 2), sizeof(t_parse_set *)); // 끝에는 NULL과 같음
	ft_memmove(temp_ptr, vlist[pos], num * sizeof(t_parse_set *));
	temp_ptr[num] = set;
	free(vlist[pos]);
	vlist[pos] = temp_ptr;
}

void	insert_vlist_blank(t_parse_set *set, t_parse_set ***vlist, size_t *s)
{
	size_t	blank_idx;

	blank_idx = find_first_blank(vlist);
	if (blank_idx == 0)
		blank_idx = 1;
	insert_vlist(set, vlist, blank_idx, s);
}

static void	process_conv_nodes(t_parse_set *head, t_parse_set ***varg_list, size_t *vlist_size)
{
	t_parse_set	*set_ptr;

	set_ptr = head;
	while (set_ptr)
	{
		if (set_ptr->conv_type)
		{
			if (set_ptr->pos_conv > 0)
				insert_vlist(set_ptr, varg_list, set_ptr->pos_conv, vlist_size);
			else
				insert_vlist_blank(set_ptr, varg_list, vlist_size);
		}
		set_ptr = set_ptr->next;
	}
}

static size_t	calculate_actual_size(t_parse_set ***varg_list, size_t vlist_size)
{
	size_t	actual_size;

	actual_size = 0;
	while (actual_size < vlist_size && varg_list[actual_size])
		actual_size++;
	return (actual_size);
}

t_parse_set	***set_varg_list(t_parse_set *head, size_t *vlist_size)
{
	t_parse_set	***varg_list;

	*vlist_size = 5;
	varg_list = vlist_init(*vlist_size);

	if (!head)
	{
		*vlist_size = 0;
		return (varg_list);
	}

	process_conv_nodes(head, varg_list, vlist_size);
	*vlist_size = calculate_actual_size(varg_list, *vlist_size);

	return (varg_list);
}
