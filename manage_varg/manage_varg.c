/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_varg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:04:09 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:06:38 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_varg.h"

static size_t	find_max_size_in_array(t_parse_set **vlist_p)
{
	size_t	i;
	size_t	max_sz;
	size_t	node_sz;

	max_sz = 0;
	i = 0;
	while (vlist_p[i])
	{
		if (vlist_p[i]->conv_type)
		{
			node_sz = find_max_type_size(vlist_p[i]);
			if (node_sz > max_sz)
				max_sz = node_sz;
		}
		i++;
	}
	return (max_sz);
}

void	set_varg(t_parse_set **vlist_p, va_list args)
{
	size_t	i;
	t_data	arg;
	size_t	max_type_size;

	if (!vlist_p || !vlist_p[0])
		return ;
	max_type_size = find_max_size_in_array(vlist_p);
	arg = extract_arg(args, max_type_size);
	i = 0;
	while (vlist_p[i])
	{
		assign_data_to_nodes(vlist_p[i], arg);
		i++;
	}
}

bool	valid_varg(t_parse_set **vlist_p)
{
	size_t		i;
	uint8_t		va_flag;
	t_parse_set	*vlist_set;

	if (!vlist_p)
		return (false);
	i = 0;
	va_flag = 0;
	while (vlist_p[i])
	{
		vlist_set = vlist_p[i];
		if (!vlist_set->conv_type)
		{
			i++;
			continue ;
		}
		if (vlist_set->pos_width || vlist_set->pos_precision)
			va_flag |= FLAG_NUM;
		if (ft_strcmp(vlist_set->conv_type, "s") == 0)
			va_flag |= FLAG_STR;
		if ((va_flag & FLAG_NUM) && (va_flag & FLAG_STR))
			return (false);
		i++;
	}
	return (true);
}

int	manage_args(va_list args, t_parse_set ***vlist, size_t *vlist_size)
{
	size_t		i;
	t_parse_set	**vlist_p;

	if (!vlist || !vlist_size || *vlist_size == 0)
		return (0);
	i = 0;
	while (i < *vlist_size)
	{
		vlist_p = vlist[i];
		if (!vlist_p)
		{
			i++;
			continue ;
		}
		if (!valid_varg(vlist_p))
		{
			*vlist_size = i;
			return (invalid_varg);
		}
		set_varg(vlist_p, args);
		i++;
	}
	return (0);
}
