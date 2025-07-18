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
	return (-1);
}

void	*parse_format(const char *format)
{
	size_t		current_idx;
	size_t		next_conv_idx;
	t_parse_set	*set;

	current_idx = 0;
	while (format[current_idx] && current_idx != -1)
	{
		set = parse_set_init();
		next_conv_idx = find_next_conv(format, current_idx);
		if (current_idx == next_conv_idx) // conv 해석
		{
			set_conv(format, &current_idx, set);
		}
		else // 전부 string
		{
			set_str(format, current_idx, next_conv_idx, set);
			current_idx = next_conv_idx;
		}
		set_lstadd_last(set);
	}
}
