/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_varg_insert.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 01:42:11 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/17 04:57:15 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_varg.h"

static int	ensure_vlist_size(t_parse_set ****vlist, size_t pos, size_t *s)
{
	if (pos == 0)
		return (-1);
	pos--;
	while (pos >= *s)
	{
		if (!vlist || !*vlist)
			return (-1);
		if (resize_vlist(vlist, s) != 0)
			return (-1);
	}
	return (0);
}

static void	create_new_vlist_slot(t_parse_set *set, t_parse_set ****vlist,
			size_t pos)
{
	(*vlist)[pos] = (t_parse_set **)ft_calloc(2, sizeof(t_parse_set *));
	if (!(*vlist)[pos])
		return ;
	(*vlist)[pos][0] = set;
}

void	extend_existing_vlist(t_parse_set *set, t_parse_set ****vlist,
			size_t pos);

void	insert_vlist(t_parse_set *set, t_parse_set ****vlist,
			size_t pos, size_t *s)
{
	if (ensure_vlist_size(vlist, pos, s) != 0)
		return ;
	if (!vlist || !*vlist)
		return ;
	if ((*vlist)[pos - 1] == NULL)
		create_new_vlist_slot(set, vlist, pos - 1);
	else
		extend_existing_vlist(set, vlist, pos - 1);
}

void	insert_vlist_blank(t_parse_set *set, t_parse_set ****vlist, size_t *s)
{
	size_t	blank_idx;

	blank_idx = find_first_blank(*vlist, *s);
	insert_vlist(set, vlist, blank_idx + 1, s);
}

