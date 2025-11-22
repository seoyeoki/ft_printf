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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	max_len;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		max_len = len1 + 1;
	else
		max_len = len2 + 1;
	return (ft_strncmp(s1, s2, max_len));
}

void	vlist_free(t_parse_set ***vlist, size_t vlist_size)
{
	size_t	i;

	if (!vlist)
		return ;
	i = 0;
	while (i < vlist_size)
	{
		if (vlist[i])
		{
			free(vlist[i]);
			vlist[i] = NULL;
		}
		i++;
	}
	free(vlist);
}

int	resize_vlist(t_parse_set ****vlist, size_t *s)
{
	t_parse_set	***temp_vlist;
	t_parse_set	***old_vlist;
	size_t		i;
	size_t		new_size;

	if (!vlist || !*vlist || !s)
		return (-1);
	new_size = *s * 2;
	temp_vlist = (t_parse_set ***)ft_calloc(new_size, sizeof(t_parse_set **));
	if (!temp_vlist)
		return (-1);
	old_vlist = *vlist;
	i = 0;
	while (i < *s)
	{
		temp_vlist[i] = old_vlist[i];
		i++;
	}
	*vlist = temp_vlist;
	*s = new_size;
	free(old_vlist);
	return (0);
}

size_t	find_first_blank(t_parse_set ***vlist, size_t vlist_size)
{
	size_t	i;

	if (!vlist)
		return (0);
	i = 0;
	while (i < vlist_size && vlist[i])
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
