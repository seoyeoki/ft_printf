/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_set_parse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_set.h"

void	set_flags(const char *format, size_t *cur, t_parse_set *set)
{
	while (format[*cur] && is_flag(format[*cur]))
	{
		if (format[*cur] == '#')
			set->flag |= FLAG_HASH;
		else if (format[*cur] == '0')
			set->flag |= FLAG_ZERO;
		else if (format[*cur] == '-')
			set->flag |= FLAG_MINUS;
		else if (format[*cur] == ' ')
			set->flag |= FLAG_SPACE;
		else if (format[*cur] == '+')
			set->flag |= FLAG_PLUS;
		(*cur)++;
	}
}

static void	parse_argnum(const char *format, size_t *cur, size_t *end, t_parse_set *set)
{
	if (is_argnum(format, *cur, end))
	{
		set->pos_conv = ft_atoi(substr_moving_idx(format, cur, *end));
		(*cur)++;
	}
}

static void	parse_precision(const char *format, size_t *cur, size_t *end, t_parse_set *set)
{
	if (is_precision(format, *cur, end))
	{
		(*cur)++;
		if (is_width(format, *cur, end))
			set->precision = ft_atoi(substr_moving_idx(format, cur, *end));
		else
			set->precision = 0;
	}
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
	
	if (is_width(format, *cur, &end))
		set->width = ft_atoi(substr_moving_idx(format, cur, end));
	
	parse_precision(format, cur, &end, set);
	
	if (is_length_modifier(format, *cur, &end))
		set->length_modifier = (char *)substr_moving_idx(format, cur, end);
	
	if (is_conversion(format, *cur, &end))
		set->conv_type = (char *)substr_moving_idx(format, cur, end);
	else
		set_str(format, start, end, set);
	
	*cur = end;
}
