/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_varg_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 02:40:55 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/17 04:33:05 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_varg.h"

void	vlist_free(t_parse_set ***vlist, size_t vlist_size)
{
	size_t	i;

	i = 0;
	while (i < vlist_size)
	{
		free(vlist[i]);
		i++;
	}
	free(vlist);
}

void	resize_vlist(t_parse_set ****vlist, size_t *s)
{
	t_parse_set	***temp_vlist;

	temp_vlist = (t_parse_set ***)ft_calloc((*s * 2), sizeof(t_parse_set **));
	ft_memmove(temp_vlist, *vlist, *s * sizeof(t_parse_set **));
	vlist_free(*vlist, *s);
	*s = *s * 2;
	*vlist = temp_vlist;
}

size_t	find_first_blank(t_parse_set ***vlist)
{
	size_t	i;

	if (!vlist)
		return (0);
	
	i = 0;
	while (vlist[i])
		i++;
	return (i);
}

size_t	varg_num(t_parse_set **vlist_pos)
{
	size_t	i;

	if (vlist_pos == NULL)
		return (0);
	i = 0;
	while (vlist_pos[i])
		i++;
	return (i);
}
