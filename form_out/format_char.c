/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:30:00 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/19 05:30:00 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form_out.h"

static char	*format_char_simple(char c)
{
	char	*result;

	result = (char *)malloc(2);
	if (!result)
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return (result);
}

static void	apply_char_left_padding(char *result, char c, int width,
				t_parse_set *set)
{
	result[0] = c;
	ft_memset(result + 1, get_padding_char(set), (size_t)(width - 1));
}

static void	apply_char_right_padding(char *result, char c, int width,
				t_parse_set *set)
{
	ft_memset(result, get_padding_char(set), (size_t)(width - 1));
	result[width - 1] = c;
}

static char	*format_char_with_width(char c, int width, t_parse_set *set)
{
	char	*result;

	result = (char *)malloc(width + 1);
	if (!result)
		return (NULL);
	if (set->flag & MINUS)
		apply_char_left_padding(result, c, width, set);
	else
		apply_char_right_padding(result, c, width, set);
	result[width] = '\0';
	set->out_len = width;
	return (result);
}

char	*format_char(t_parse_set *set)
{
	char	c;
	int		width;

	c = (char)set->data.i;
	width = set->width;
	if (width > 1)
		return (format_char_with_width(c, width, set));
	else
	{
		set->out_len = 1;
		return (format_char_simple(c));
	}
}

