/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_set_parse_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 01:06:37 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/16 03:04:04 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_set.h"

static bool	is_precision(const char *format, size_t cur_idx, size_t *end_idx)
{
	if (format[cur_idx] == '.')
	{
		*end_idx = cur_idx + 1;
		return (true);
	}
	return (false);
}

void	parse_precision(const char *format, size_t *cur, size_t *end,
			t_parse_set *set)
{
	size_t	start;
	char	*tmp;

	if (is_precision(format, *cur, end))
	{
		(*cur)++;
		start = *cur;
		while (ft_isdigit(format[*cur]))
			(*cur)++;
		if (*cur > start)
		{
			*end = *cur;
			tmp = (char *)ft_substr(format, start, *cur - start);
			set->precision = ft_atoi(tmp);
			free(tmp);
		}
		else
		{
			set->precision = 0;
			*end = *cur;
		}
	}
}
