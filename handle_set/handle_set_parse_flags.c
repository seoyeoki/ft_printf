/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_set_parse_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 01:06:37 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/16 03:04:04 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_set.h"

static void	apply_flag(char c, t_parse_set *set)
{
	if (c == '#')
		set->flag |= HASH;
	else if (c == '-')
		set->flag |= MINUS;
	else if (c == ' ')
		set->flag |= SPACE;
	else if (c == '+')
		set->flag |= PLUS;
}

static void	handle_zero_flag(const char *format, size_t *cur, t_parse_set *set)
{
	set->flag |= ZERO;
	if (ft_isdigit(format[*cur + 1]))
	{
		(*cur)++;
		return ;
	}
	(*cur)++;
}

void	set_flags(const char *format, size_t *cur, t_parse_set *set)
{
	char	c;

	while (format[*cur])
	{
		c = format[*cur];
		if (c == '#' || c == '-' || c == ' ' || c == '+')
		{
			apply_flag(c, set);
			(*cur)++;
		}
		else if (c == '0')
		{
			handle_zero_flag(format, cur, set);
			if (ft_isdigit(format[*cur]))
				break ;
		}
		else
			break ;
	}
}
