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

t_parse_set	***vlist_init(size_t vlist_size)
{
	t_parse_set	***vlist;

	vlist = (t_parse_set ***)ft_calloc(vlist_size, sizeof(t_parse_set **));
	return (vlist);
}

void	insert_vlist(t_parse_set *set, t_parse_set ****vlist,
			size_t pos, size_t *s);
void	insert_vlist_blank(t_parse_set *set, t_parse_set ****vlist, size_t *s);

static void	process_conv_nodes(t_parse_set *head,
				t_parse_set ****varg_list, size_t *vlist_size)
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

t_parse_set	***set_varg_list(t_parse_set *head, size_t *vlist_size)
{
	t_parse_set	***varg_list;
	size_t		actual_size;

	*vlist_size = 5;
	varg_list = vlist_init(*vlist_size);
	if (!varg_list)
		return (NULL);
	if (!head)
	{
		*vlist_size = 0;
		return (varg_list);
	}
	actual_size = *vlist_size;
	process_conv_nodes(head, &varg_list, &actual_size);
	if (!varg_list)
		return (NULL);
	*vlist_size = find_first_blank(varg_list, actual_size);
	return (varg_list);
}
