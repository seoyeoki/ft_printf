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

#include "handle_set.h"
#include "manage_varg.h"

t_parse_set	***vlist_init(size_t vlist_size) // util로 이동하기
{
	t_parse_set	***vlist;

	vlist = (t_parse_set ***)ft_calloc(vlist_size * sizeof(t_parse_set **));
	return (vlist);
}

void	insert_vlist(t_parse_set *set, t_parse_set ***vlist, size_t pos, size_t *s)
{
	size_t		num;
	t_parse_set	**temp_ptr;

	pos--;
	if (pos >= *s)
		resize_vlist(&vlist, s);
	num = varg_num(vlist[pos]);
	temp_ptr = (t_parse_set **)ft_calloc((num + 2) * sizeof(t_parse_set *)); // 끝에는 NULL과 같음
	ft_memmove(temp_ptr, vlist[pos], num * sizeof(t_parse_set *));
	temp_ptr[num] = set;
	free(vlist[pos]);
	vlist[pos] = temp_ptr;
}

void	insert_vlist_blank(t_parse_set *set, t_parse_set ***vlist, size_t *s)
{
	size_t	blank_idx;

	blank_idx = find_first_blank(vlist);
	insert_vlist(set, vlist, blank_idx, s);
}

t_parse_set	***set_varg_list(size_t *vlist_size)
{
	t_parse_set	***varg_list;
	t_parse_set	*set_ptr;

	*vlist_size = 5;
	varg_list = vlist_init(*vlist_size);
	set_ptr = head;
	while (set_ptr) // 사실 전부 if거나 전부 else여야 정상 동작
	{
		if (set_ptr->pos_width > 0)
			insert_vlist(set, varg_list, set_ptr->pos_width, vlist_size);
		else
			insert_vlist_blank(set, varg_list, vlist_size);
		if (set_ptr->pos_precision > 0)
			insert_vlist(varg_list, set_ptr->pos_precision, vlist_size);
		else
			insert_vlist_blank(set, varg_list, vlist_size);
		if (set_ptr->pos_conversion > 0)
			insert_vlist(varg_list, set_ptr->pos_conversion, vlist_size);
		else
			insert_vlist_blank(set, varg_list, vlist_size);
		set_ptr = set_ptr->next;
	}
	return (varg_list);
}
