/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_varg_extend.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 01:42:11 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/17 04:57:15 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_varg.h"

static void	copy_and_extend_vlist(t_parse_set **old_ptr, t_parse_set **temp_ptr,
			size_t num, t_parse_set *set)
{
	ft_memmove(temp_ptr, old_ptr, num * sizeof(t_parse_set *));
	temp_ptr[num] = set;
}

void	extend_existing_vlist(t_parse_set *set, t_parse_set ****vlist,
			size_t pos)
{
	size_t		num;
	t_parse_set	**temp_ptr;
	t_parse_set	**old_ptr;

	num = varg_num((*vlist)[pos]);
	temp_ptr = (t_parse_set **)ft_calloc((num + 2), sizeof(t_parse_set *));
	if (!temp_ptr)
		return ;
	old_ptr = (*vlist)[pos];
	copy_and_extend_vlist(old_ptr, temp_ptr, num, set);
	(*vlist)[pos] = temp_ptr;
	free(old_ptr);
}

