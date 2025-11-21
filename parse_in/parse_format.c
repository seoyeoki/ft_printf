/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:33:07 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/16 02:54:12 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_format.h"
#include "handle_set.h"

bool	ispercent(char c)
{
	if (c == '%')
		return (true);
	else
		return (false);
}

size_t	find_next_conv(const char *format, size_t current_idx)
{
	while (format[current_idx])
	{
		if (ispercent(format[current_idx]))
			return (current_idx);
		current_idx++;
	}
	return (SIZE_MAX);
}

void	parse_format(const char *format, t_parse_set **head, t_parse_set **tail)
{
	size_t		current_idx;
	size_t		next_conv_idx;
	t_parse_set	*set;

	current_idx = 0;
	while (format[current_idx])
	{
		set = parse_set_init();
		next_conv_idx = find_next_conv(format, current_idx);
		if (next_conv_idx == SIZE_MAX)
		{
			set_str(format, current_idx, ft_strlen(format), set);
			current_idx = ft_strlen(format);
		}
		else if (current_idx == next_conv_idx)
		{
			set_conv(format, &current_idx, set);
		}
		else
		{
			set_str(format, current_idx, next_conv_idx, set);
			current_idx = next_conv_idx;
		}
		set_lstadd_last(head, tail, set);
	}
}
