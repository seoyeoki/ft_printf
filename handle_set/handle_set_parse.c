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

void	set_flags(const char *format, size_t *cur, t_parse_set *set);
void	parse_precision(const char *format, size_t *cur, size_t *end, \
			t_parse_set *set);

static void	parse_argnum(const char *format, size_t *cur, size_t *end, \
				t_parse_set *set)
{
	if (is_argnum(format, *cur, end))
	{
		set->pos_conv = ft_atoi(substr_moving_idx(format, cur, *end));
		(*cur)++;
	}
}

static void	parse_width(const char *format, size_t *cur, size_t *end, \
				t_parse_set *set)
{
	char	*tmp;

	if (is_width(format, *cur, end))
	{
		tmp = (char *)substr_moving_idx(format, cur, *end);
		set->width = ft_atoi(tmp);
		free(tmp);
	}
}

static void	parse_length_and_conv(const char *format, size_t *cur, size_t *end, \
				t_parse_set *set)
{
	if (is_length_modifier(format, *cur, end))
		set->length_modifier = (char *)substr_moving_idx(format, cur, *end);
	if (is_conversion(format, *cur, end))
		set->conv_type = (char *)substr_moving_idx(format, cur, *end);
}

void	set_conv(const char *format, size_t *cur, t_parse_set *set)
{
	size_t	start;
	size_t	end;

	start = *cur;
	(*cur)++;
	end = *cur;
	parse_argnum(format, cur, &end, set);
	set_flags(format, cur, set);
	parse_width(format, cur, &end, set);
	parse_precision(format, cur, &end, set);
	parse_length_and_conv(format, cur, &end, set);
	if (!set->conv_type)
	{
		end = *cur;
		set_str(format, start, end, set);
	}
	*cur = end;
}
