/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 01:41:26 by seoykim           #+#    #+#             */
/*   Updated: 2025/07/16 02:43:51 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_set.h"

bool	is_argnum(const char *format, size_t cur_idx, size_t	*end_idx)
{
	char	c;

	while (format[cur_idx])
	{
		c = format[cur_idx];
		if (c == '$')
		{
			*end_idx = cur_idx;
			return (true);
		}
		if (isdigit(c))
			cur_idx++;
		else
			return (false);
	}
	return (false);
}

bool	is_width(const char *format, size_t cur_idx, size_t *end_idx)
{
	if (!format[cur_idx])
		return (false);
	if (!isdigit(format[cur_idx]) || format[cur_idx] == '0')
		return (false);
	while (isdigit(format[cur_idx]))
		cur_idx++;
	*end_idx = cur_idx;
	return (true);
}

bool	is_length_modifier(const char *format, size_t cur_idx, size_t *end_idx)
{
	int			i;
	int			lm_len;
	const char	(*lm_list)[8];

	if (!format[cur_idx])
		return (false);
	lm_list[0] = "hh";
	lm_list[1] = "h";
	lm_list[2] = "l";
	lm_list[3] = "ll";
	lm_list[4] = "j";
	lm_list[5] = "z";
	lm_list[6] = "t";
	lm_list[7] = NULL;
	i = 0;
	while (lm_list[i])
	{
		lm_len = ft_strlen(lm_list[i]);
		if (ft_strncmp(&format[cur_idx], lm_list[i], lm_len))
		{
			*end_idx = cur_idx + lm_len;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	is_conversion(const char *format, size_t cur_idx, size_t *end_idx)
{
	int			i;
	const char	*conv_list_str;

	if (!format[cur_idx])
		return (false);
	*conv_list_str = "cspdiuxX%";
	i = 0;
	while (conv_list_str[i])
	{
		if (format[cur_idx] == conv_list_str[i])
		{
			*end_idx = cur_idx + 1;
			return (true);
		}
		i++;
	}
	return (false);
}
