/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_set_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 01:06:37 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/16 03:04:04 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_set.h"

void	set_conv(const char *format, size_t *cur, t_parse_set *set)
{
	size_t	start;
	size_t	end;

	start = *cur;
	(*cur)++;
	end = *cur;
	if (is_argnum(format, *cur, &end))
	{
		set->pos_conv = ft_atoi(substr_moving_idx(format, cur, end));
		(*cur)++;
	}
	
	if (is_width(format, *cur, &end))
		set->width = ft_atoi(substr_moving_idx(format, cur, end));
	if (is_length_modifier(format, *cur, &end))
	{
		set->length_modifier = (char *)substr_moving_idx(format, cur, end);
	}
	if (is_conversion(format, *cur, &end))
		set->conv_type = (char *)substr_moving_idx(format, cur, end);
	else
		set_str(format, start, end, set);
	*cur = end;
}
